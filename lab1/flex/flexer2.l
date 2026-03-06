%option noyywrap
%option c++
%x OPT ARG
%%
<INITIAL>{
^[a-zA-Z]+ {return 1;BEH}
}
