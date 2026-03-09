%option noyywrap
%option c++
%option batch
%x OPT ARG
%%

<INITIAL>{
^[a-zA-Z]+ {BEGIN(OPT);return 1;}
. {return 3;}

}

<OPT>{
[ ]+-[a-zA-Z]+ { }
[ ]+[a-zA-Z]+ {BEGIN(ARG);}
[ ]*\r?\n {BEGIN(INITIAL);return 2;}
. {BEGIN(INITIAL);return 3;}
}

<ARG>{
[ ]+[a-zA-Z]+ { }
[ ]*\r?\n {BEGIN(INITIAL);return 2;}
. {BEGIN(INITIAL);return 3;}
}

<<EOF>> {return 0;}
%%