%option noyywrap
%option c++
%x TAIL
%%
<INITIAL>{
^([a-zA-Z]+)/([ ]+-[a-zA-Z]+)*([ ]+[a-zA-Z]+)*[ ]*\r?\n {BEGIN(TAIL);return 1;}
\r?\n {return 2;}
. {}
}
<TAIL>{
 \r?\n     { BEGIN(INITIAL); }
 . {}
}
<<EOF>> {return 0;}
