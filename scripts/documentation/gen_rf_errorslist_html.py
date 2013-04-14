#---------------------------------------------------------------------------------------#
# @author Lefteris                                                                      #
# @date 21/05/2012                                                                      #
#                                                                                       #
# This is a python script whose purpose is to parse the library's setup file where      #
# all the library's main errors are are stored in an enumeration and create an html     #
# file where the errors will be listed and can easily be included n the doxygen         #
# documentation.                                                                        #
#---------------------------------------------------------------------------------------#

#stuff to import to be able to open files in the parent directory
import os.path
import os
import sys

from ProjectPaths import docsexamplepath

def generate_Errors_List():
    print("gen_rf_errorslist_html script starts operation");

    #create the output html file in the proper directory. If the directory does not exist, create it
    if (os.path.exists(docsexamplepath) == False):
        os.mkdir(docsexamplepath)
    f = open(docsexamplepath+"/rf_errorslist.html","w",encoding="utf8");
    # the setup file
    inF = open(os.path.dirname(sys.argv[0]) + "/../../include/Definitions/retcodes.h","r",encoding="utf8");

    f.write("<!-- Automatically generated by the script gen_rf_errorslist_html.py -->");
    #read the setup file until we get to the start of the errors enumeration
    while(inF.readline() != "// LIST OF REFU LIBRARY ERRORS\n"):
        pass #keep reading

    #pass the enum{
    line = inF.readline();
    #value counter
    valueCounter = 0;
    #main reading loop. until the end of the enum
    while("};" not in line):
        #if this is the start of a category
        if("/*" in line):
            #get the category. No check is done here since I am sure that it is correctly written.
            category = line.partition("/*")[2];
            category = category.partition("*/")[0];
            category = category.lstrip();
            category = category.rstrip();
            #print("Got in here with category "+category);
            #write the category to the output
            f.write("<h2 class=\"errorsList\">"+category+"</h2>\n");
            f.write("<table class=\"errorsList\"><tr class=\"errorsList\"><th class=\"errorsList\">ERROR NAME</th><th class=\"errorsList\">ERROR VALUE</th><th class=\"errorsList\">ERROR DESCRIPTION</th></tr>");
            #now start reading the errors and creating the table
            line = inF.readline();
            while("," in line):#for each group
                #print("Got in with line \n"+line+"\n\n");
                part = line.partition(",");
                errorName = part[0].lstrip();
                #print("Premature error name is: "+errorName);
                #if there is a value set this means we got to set the value counter here
                if("=" in errorName):
                    morepart = errorName.partition("=");
                    #print("WITH=:The value is "+morepart[2]);
                    valueCounter = int(morepart[2]);
                    errorName = morepart[0];
                    #print("WITH=:The error name is "+errorName);
                else:#else increase it
                    valueCounter = valueCounter+1;
                    #print("The value is "+str(valueCounter));
                    #print("The error name is "+errorName);

                #finally get the description
                errorDescription = part[2].replace("//","");
                errorDescription = errorDescription.rstrip("\n");
                #print("The description is "+errorDescription);
                #add a row to the list
                f.write("<tr class=\"errorsList\"><td class=\"errorsList\">"+errorName+"</td>\n");
                f.write("<td class=\"errorsList_Value\">"+str(valueCounter)+"</td>\n");
                f.write("<td class=\"errorsList\">"+errorDescription+"</td></tr>\n");
                #go to the next line
                line = inF.readline();
            #at the end of a category make sure to write a clear:both; div
           # f.write("<div style=\"clear:both;\"></div>\n");
            f.write("</table>\n");
        else:
            #go to the next line
            line = inF.readline();

    #close both files in the end
    f.close();
    inF.close();
    print("gen_rf_errorslist_html script finished");
