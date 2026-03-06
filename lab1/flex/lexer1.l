%option noyywrap
%option c++
%%
^[a-zA-Z]+ {return 1;}
([ ]+-[a-zA-Z]+)*([ ]+[a-zA-Z]+)*[ ]*\r?\n {return 2;}
. {return 3;}
<<EOF>> {return 0;}
