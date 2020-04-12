#include <stdlib.h>
#include <string>
#include <vector>

#define WORKBENCH_FIRST_LINE "    workbench.colorCustomizations\": {\n"
#define WORKBENCH_LAST_LINE "    }\n\n"
static const std::vector<std::string> baseColorVariables = {
    "        \"activityBar.activeBorder\": ",
    "        \"activityBar.border\": ",
    "        \"activityBar.foreground\": ",
    "        \"activityBar.inactiveForeground\": ",
    "        \"activityBar.activeBorder\": ",
    "        \"activityBarBadge.background\": ",
    "        \"badge.foreground\": ",
    "        \"button.foreground\": ",
    "        \"checkbox.foreground\": ",
    "        \"debugToolBar.background\": ",
    "        \"dropdown.foreground\": ",
    "        \"editor.background\": ",
    "        \"editor.focusedStackFrameHighlightBackground\": ",
    "        \"editor.selectionForeground\": ",
    "        \"editor.stackFrameHighlightBackground\": ",
    "        \"editorGroupHeader.tabsBackground\": ",
    "        \"extensionButton.prominentForeground\": ",
    "        \"input.background\": ",
    "        \"list.activeSelectionForeground\": ",
    "        \"list.inactiveSelectionForeground\": ",
    "        \"menu.background\": ",
    "        \"menu.selectionForeground\": ",
    "        \"menubar.selectionForeground\": ",
    "        \"peekViewEditor.background\": ",
    "        \"peekViewEditorGutter.background\": ",
    "        \"peekViewResult.background\": ",
    "        \"peekViewResult.selectionForeground\": ",
    "        \"peekViewTitleDescription.foreground\": ",
    "        \"peekViewTitleLabel.foreground\": ",
    "        \"sideBar.background\": ",
    "        \"sideBarSectionHeader.foreground\": ",
    "        \"statusBar.foreground\": ",
    "        \"tab.activeForeground\": ",
    "        \"tab.inactiveBackground\": ",
    "        \"terminal.background\": ",
    "        \"titleBar.activeForeground\": ",
    "        \"titleBar.inactiveForeground\": ",
    "        \"welcomePage.background\": ",
    "        \"welcomePage.buttonBackground\": ",
    "        \"activityBar.activeBorder\": ",
};
static const std::vector<std::string> primaryColorVariables = {
    "        \"activityBar.background\": ",
    "        \"badge.background\": ",
    "        \"button.background\": ",
    "        \"debugToolBar.border\": ",
    "        \"editor.foreground\": ",
    "        \"editorCursor.foreground\": ",
    "        \"editorGroup.border\": ",
    "        \"editorLineNumber.activeForeground\": ",
    "        \"editorLineNumber.foreground\": ",
    "        \"extensionButton.prominentHoverBackground\": ",
    "        \"input.border\": ",
    "        \"input.foreground\": ",
    "        \"list.hoverBackground\": ",
    "        \"menu.foreground\": ",
    "        \"sideBar.border\": ",
    "        \"sideBar.dropBackground\": ",
    "        \"sideBar.foreground\": ",
    "        \"sideBarTitle.foreground\": ",
    "        \"statusBar.background\": ",
    "        \"tab.border\": ",
    "        \"tab.inactiveForeground\": ",
    "        \"terminal.border\": ",
    "        \"terminal.foreground\": ",
    "        \"terminalCursor.background\": ",
    "        \"terminalCursor.foreground\": ",
    "        \"titleBar.activeBackground\": ",
    "        \"titleBar.inactiveBackground\": ",
};
static const std::vector<std::string> secondaryColorVariables = {
    "        \"activityBar.dropBackground\": ",
    "        \"activityBarBadge.foreground\": ",
    "        \"button.hoverBackground\": ",
    "        \"checkbox.background\": ",
    "        \"checkbox.border\": ",
    "        \"dropdown.background\": ",
    "        \"dropdown.border\": ",
    "        \"dropdown.listBackground\": ",
    "        \"editorBracketMatch.background\": ",
    "        \"editorBracketMatch.border\": ",
    "        \"editorGroup.dropBackground\": ",
    "        \"editorGroupHeader.tabsBorder\": ",
    "        \"extensionButton.prominentBackground\": ",
    "        \"list.activeSelectionBackground\": ",
    "        \"list.inactiveSelectionBackground\": ",
    "        \"menu.selectionBackground\": ",
    "        \"menu.selectionBorder\": ",
    "        \"menubar.selectionBackground\": ",
    "        \"menubar.selectionBorder\": ",
    "        \"peekViewEditor.matchHighlightBackground\": ",
    "        \"peekViewEditor.matchHighlightBorder\": ",
    "        \"peekViewResult.selectionBackground\": ",
    "        \"peekViewTitle.background\": ",
    "        \"scrollbar.shadow\": ",
    "        \"scrollbarSlider.activeBackground\": ",
    "        \"scrollbarSlider.background\": ",
    "        \"scrollbarSlider.hoverBackground\": ",
    "        \"sideBarSectionHeader.background\": ",
    "        \"sideBarSectionHeader.border\": ",
    "        \"tab.activeBackground\": ",
    "        \"tab.activeBorder\": ",
    "        \"tab.hoverBackground\": ",
    "        \"terminal.selectionBackground\": ",
    "        \"textLink.activeForeground\": ",
    "        \"welcomePage.buttonHoverBackground\": ",
};
#define TOKEN_FIRST_LINE "    editor.tokenColorCustomizations\": {\n"
#define TOKEN_LAST_LINE "    }\n"
static const std::vector<std::string> tokenPrimaryColorVariables = {
    "        \"strings\": ",
    "        \"numbers\": ",
    "        \"keywords\": ",
    "        \"types\": ",
    "        \"functions\": ",
    "        \"variables\": ",
    "        \"semanticHighlighting\": true",
};
static const std::vector<std::string> tokenSecondaryColorVariables = {
    "        \"comments\": ",
};

int main(int argc, char** argv)
{
    // Parse command line arguments
    if (argc == 1)
    {
        printf("ERROR: a minimum of 1 argument must be passed, try '--help'\n");
        return EXIT_FAILURE;
    }
    if ((strcmp(argv[1], "--help") == 0) ||
        (strcmp(argv[1], "-h") == 0))
    {
        printf("usage: ./keycap_theme_generator --base <hex RGB pattern> --primary <hex RGB pattern> --secondary <hex RGB pattern>\n"
               "parameters:\n"
               "\t-b, --base       hexadecimal pattern representing RGB base color, e.g. ff8800 (no leading '0x' or '#')\n"
               "\t-p, --primary    hexadecimal pattern representing RGB primary color, e.g. 88ff00 (no leading '0x' or '#')\n"
               "\t-s, --secondary  hexadecimal pattern representing RGB secondary color, e.g. 0088ff (no leading '0x' or '#')\n");
        return EXIT_FAILURE;
    }
    if (argc < 7)
    {
        printf("ERROR: 6 arguments are required\n");
        return EXIT_FAILURE;
    }
    std::string baseColor;
    std::string primaryColor;
    std::string secondaryColor;
    bool foundBaseColor = false;
    bool foundPrimaryColor = false;
    bool foundSecondaryColor = false;
    int argi = 1; // Skip initial parameter as that's the executable
    while (argi < argc)
    {
        if ((strcmp(argv[argi], "--base") == 0) ||
            (strcmp(argv[argi], "-b") == 0))
        {
            baseColor = argv[argi + 1];
            foundBaseColor = true;
            argi++;
        }
        else if ((strcmp(argv[argi], "--primary") == 0) ||
                 (strcmp(argv[argi], "-p") == 0))
        {
            primaryColor = argv[argi + 1];
            foundPrimaryColor = true;
            argi++;
        }
        else if ((strcmp(argv[argi], "--secondary") == 0) ||
                 (strcmp(argv[argi], "-s") == 0))
        {
            secondaryColor = argv[argi + 1];
            foundSecondaryColor = true;
            argi++;
        }
        else
        {
            printf("WARNING: skipping unknown parameter '%s'\n", argv[argi]);
        }
        argi++;
    }
    if (!foundBaseColor)
    {
        printf("ERROR: missing base color parameter\n");
        return EXIT_FAILURE;
    }
    if (!foundPrimaryColor)
    {
        printf("ERROR: missing primary color parameter\n");
        return EXIT_FAILURE;
    }
    if (!foundSecondaryColor)
    {
        printf("ERROR: missing secondary color parameter\n");
        return EXIT_FAILURE;
    }

    // Workbench
    std::string output = WORKBENCH_FIRST_LINE;
    for (size_t i= 0; i < baseColorVariables.size(); i++)
    {
        std::string line = baseColorVariables[i] + "\"#" + baseColor + "\"\n";
        output += line;
    }
    for (size_t i= 0; i < primaryColorVariables.size(); i++)
    {
        std::string line = primaryColorVariables[i] + "\"#" + primaryColor + "\"\n";
        output += line;
    }
    for (size_t i= 0; i < secondaryColorVariables.size(); i++)
    {
        std::string line = secondaryColorVariables[i] + "\"#" + secondaryColor + "\"\n";
        output += line;
    }
    output += WORKBENCH_LAST_LINE;

    // Tokens
    output += TOKEN_FIRST_LINE;
    for (size_t i = 0; i < tokenPrimaryColorVariables.size(); i++)
    {
        std::string line = tokenPrimaryColorVariables[i] + "\"#" + primaryColor + "\"\n";
        output += line;
    }
    for (size_t i = 0; i < tokenSecondaryColorVariables.size(); i++)
    {
        std::string line = tokenSecondaryColorVariables[i] + "\"#" + secondaryColor + "\"\n";
        output += line;
    }
    output += TOKEN_LAST_LINE;

    // Print and write out
    printf("%s", output.c_str());

    return EXIT_SUCCESS;
}