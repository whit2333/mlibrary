# Options library




Doxygen Documentation
---------------------

To document c++ http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html#cppblock
Special commands: https://www.stack.nl/~dimitri/doxygen/manual/commands.html


To create doxy file:

 doxygen -g


Changes:

 - PROJECT_NAME           = "Options"
 - PROJECT_NUMBER         = 1.0
 - PROJECT_BRIEF          = "Option Library Framework"
 - OPTIMIZE_OUTPUT_FOR_C  = YES
 - BUILTIN_STL_SUPPORT    = YES
 - QUIET                  = YES
 - SOURCE_BROWSER         = YES
 - HTML_COLORSTYLE_SAT    = 50
 - GENERATE_LATEX         = NO  (change to YES to generate latex)
 - HIDE_UNDOC_RELATIONS   = NO
 - HAVE_DOT               = YES
 - UML_LOOK               = YES
 - UML_LIMIT_NUM_FIELDS   = 0
 - DOT_FONTSIZE           = 12
 - HTML_DYNAMIC_SECTIONS  = YES
 - EXTRACT_PRIVATE        = YES (change to NO show just the public interface)
 - EXCLUDE                = example.cc


