# CowTownCollegeAlumniProgram
This program takes a list of donors that have donated to Cow Town College and displays the donors in various orders and views.
Program requirements:
1) The program should loop back to the 1st menu after each report and only exit if the user selects
item 0.
2) Create a class to hold each record as a vector of objects to be used by the main program.
3) The class should contain all necessary Set and Get functions, 2 constructors, a copy constructor,
overloaded operators to be able to sort the records in their proper order.
4) Be sure to include error handling inside your class definitions, when appropriate, to protect the
member variables (properties).
5) Read the members.csv file into the array of member objects in the mian() function.
6) Create a class that produces an HTML table. This class should contain an overloaded friend <<
operator for sending the output to an HTML table report file. This one overloaded operator
function should be capable of writing the title, headings and each line of output by passing in
the tags for the HTML.
7) Create functions for main() to call for the menu, sorting and each report. No global variables are
allowed. You must pass in the vector array of objects, file handlers, etc., as needed, to each
function.
8) Prompt the user for a file name to save each report they select after they make the selection.
9) Save each report in a separate file, as named by the user.
