#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

#import "FileConverterWindow.h"
#import "DocumentConverter.h"
#import "ImageConverter.h"


@interface FileConverterWindow ()

@property (nonatomic, strong) NSTextField *fileNameLabel; 
@property (nonatomic, strong) NSPopUpButton *targetFileTypeDropdown; 
@property (nonatomic, strong) NSButton *convertButton; 
@property (nonatomic, strong) NSButton *openButton;
@property (nonatomic, strong) NSTextField *exportPathLabel;
@property (nonatomic, strong) NSString *selectedExportPath;

@end

@implementation FileConverterWindow

- (instancetype)init {
    self = [super init];
    if (self) {
        // Window setup
        NSRect frame = NSMakeRect(0, 0, 600, 400); 
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [window setBackgroundColor:[NSColor whiteColor]]; 
        [self setWindow:window];
        
        self.openButton = [[NSButton alloc] initWithFrame:NSMakeRect(20, 20, 100, 30)];
        [self.openButton setTitle:@"Open File"];
        [self.openButton setTarget:self];
        [self.openButton setAction:@selector(openFile:)];
        [self.openButton setBezelStyle:NSBezelStyleRounded];
        [self.openButton setFont:[NSFont systemFontOfSize:14]];

        [self.openButton setAttributedTitle:[[NSAttributedString alloc] initWithString:@"Open File" attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}]];
        [window.contentView addSubview:self.openButton];
        
        self.fileNameLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(140, 20, 400, 30)];
        [self.fileNameLabel setEditable:NO];
        [self.fileNameLabel setBordered:NO];
        [self.fileNameLabel setBackgroundColor:[NSColor clearColor]];
        [self.fileNameLabel setFont:[NSFont systemFontOfSize:14]];
        [self.fileNameLabel setTextColor:[NSColor blackColor]]; 
        [self.fileNameLabel setStringValue:@"No file selected"];
        [window.contentView addSubview:self.fileNameLabel];

        NSTextField *targetFileTypeLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(20, 80, 200, 20)];
        [targetFileTypeLabel setEditable:NO];
        [targetFileTypeLabel setBordered:NO];
        [targetFileTypeLabel setBackgroundColor:[NSColor clearColor]];
        [targetFileTypeLabel setFont:[NSFont systemFontOfSize:12]];
        [targetFileTypeLabel setStringValue:@"Set Targeted File Type"];
        [window.contentView addSubview:targetFileTypeLabel];

        self.targetFileTypeDropdown = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(20, 50, 200, 30)];
        [self.targetFileTypeDropdown addItemWithTitle:@"Select File Type"];
        [self.targetFileTypeDropdown addItemWithTitle:@"PDF"];
        [self.targetFileTypeDropdown addItemWithTitle:@"JPEG"];
        [self.targetFileTypeDropdown addItemWithTitle:@"PNG"];
        [self.targetFileTypeDropdown setFont:[NSFont systemFontOfSize:14]];

        [self.targetFileTypeDropdown.itemArray enumerateObjectsUsingBlock:^(NSMenuItem *item, NSUInteger idx, BOOL *stop) {
            [item setAttributedTitle:[[NSAttributedString alloc] initWithString:item.title attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}]];
        }];
        
        [self.targetFileTypeDropdown setAttributedTitle:[[NSAttributedString alloc] initWithString:@"Select File Type" attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}]];
        [window.contentView addSubview:self.targetFileTypeDropdown];
        
        self.convertButton = [[NSButton alloc] initWithFrame:NSMakeRect(240, 50, 120, 30)]; // Increased width to 120
        [self.convertButton setTitle:@"Convert File"];
        [self.convertButton setTarget:self];
        [self.convertButton setAction:@selector(convertFile:)];
        [self.convertButton setBezelStyle:NSBezelStyleRounded];
        [self.convertButton setFont:[NSFont systemFontOfSize:14]];

        [self.convertButton setAttributedTitle:[[NSAttributedString alloc] initWithString:@"Convert File" attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}]];
        [window.contentView addSubview:self.convertButton];

        self.exportPathLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(20, 120, 400, 30)];
        [self.exportPathLabel setEditable:NO];
        [self.exportPathLabel setBordered:NO];
        [self.exportPathLabel setBackgroundColor:[NSColor clearColor]];
        [self.exportPathLabel setFont:[NSFont systemFontOfSize:14]];
        [self.exportPathLabel setTextColor:[NSColor blackColor]];
        [self.exportPathLabel setStringValue:@"No export path selected"];
        [window.contentView addSubview:self.exportPathLabel];

        // Moved "Select Export Path" button down by 40 pixels
        NSButton *selectedExportPathButton = [[NSButton alloc] initWithFrame:NSMakeRect(240, 160, 120, 30)];
        [selectedExportPathButton setTitle:@"Select Export Path"];
        [selectedExportPathButton setTarget:self];
        [selectedExportPathButton setAction:@selector(selectExportPath:)];
        [selectedExportPathButton setBezelStyle:NSBezelStyleRounded];
        [selectedExportPathButton setFont:[NSFont systemFontOfSize:14]];
        [selectedExportPathButton setAttributedTitle:[[NSAttributedString alloc] initWithString:@"Select Export Path" attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}]];
        [window.contentView addSubview:selectedExportPathButton];

        [[window contentView] setWantsLayer:YES];
    }
    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:nil];
}

- (void)openFile:(id)sender {
    NSLog(@"Open File method called");

    NSOpenPanel *panel = [NSOpenPanel openPanel];
    
    panel.allowedContentTypes = @[
        [UTType typeWithIdentifier:@"public.plain-text"], // for .txt files
        [UTType typeWithIdentifier:@"com.adobe.pdf"],    // for .pdf files
        [UTType typeWithIdentifier:@"public.jpeg"]       // for .jpg files
    ]; 

    panel.allowsMultipleSelection = NO;

    if ([panel runModal] == NSModalResponseOK) {
        NSURL *selectedFileURL = [panel URL];
        NSLog(@"File selected: %@", selectedFileURL);

        [self.fileNameLabel setStringValue:selectedFileURL.lastPathComponent];
    }
}

- (void)convertFile:(id)sender {
    NSString *selectedFileType = [self.targetFileTypeDropdown titleOfSelectedItem];
    
    if ([selectedFileType isEqualToString:@"Select File Type"]) {
        NSLog(@"No file type selected for conversion");
        return;
    }

    if (!self.selectedExportPath) {
        NSLog(@"No export path selected");
        return;
    }
    
    NSLog(@"Starting conversion to %@", selectedFileType);
    
}

- (void)selectExportPath:(id)sender {
    NSSavePanel *savePanel = [NSSavePanel savePanel];
    
    // Updated to use allowedContentTypes instead of the deprecated allowedFileTypes
    savePanel.allowedContentTypes = @[
        [UTType typeWithIdentifier:@"public.plain-text"], 
        [UTType typeWithIdentifier:@"com.adobe.pdf"],    
        [UTType typeWithIdentifier:@"public.jpeg"],      
        [UTType typeWithIdentifier:@"public.png"]
    ];
    
    [savePanel beginWithCompletionHandler:^(NSInteger result) {
        if (result == NSModalResponseOK) {
            NSURL *selectedPathURL = [savePanel URL];
            self.selectedExportPath = selectedPathURL.path;
            [self.exportPathLabel setStringValue:[NSString stringWithFormat:@"Export path: %@", self.selectedExportPath]];

            NSLog(@"Export path selected: %@", self.selectedExportPath);
        }
    }];
}

@end

