" Vim syntax file for Corin (.corin)
" Language: Corin
" Maintainer: Corin Language Team
" Latest Revision: 2026

if exists("b:current_syntax")
  finish
endif

" ── Keywords ──────────────────────────────────────────────────────────────
syn keyword corinKeyword     if else elif for while break continue return
syn keyword corinKeyword     match case default in pass del
syn keyword corinKeyword     import from as
syn keyword corinDeclaration fn class trait impl macro enum
syn keyword corinModifier    pub priv static mut owned where dyn
syn keyword corinAsync       async await chan go select
syn keyword corinException   try catch finally throw raise
syn keyword corinType        int float double str bool void any list dict tuple set bytes char
syn keyword corinConstant    true false none None Some Ok Err Self

" ── Decorators ────────────────────────────────────────────────────────────
syn match corinDecorator     "@[a-zA-Z_][a-zA-Z0-9_]*"

" ── Doc comments ──────────────────────────────────────────────────────────
syn match corinDocComment    "///.*$"
syn match corinDocComment    "#!.*$"

" ── Comments ──────────────────────────────────────────────────────────────
syn match corinComment       "#[^!][^\n]*$"
syn match corinComment       "#$"

" ── Strings ───────────────────────────────────────────────────────────────
syn region corinFString      start=/f"/ end=/"/ contains=corinInterp,corinEscape
syn region corinFString      start=/f'/ end=/'/ contains=corinInterp,corinEscape
syn region corinString       start=/"""/ end=/"""/ contains=corinEscape
syn region corinString       start=/"/ end=/"/ contains=corinEscape
syn region corinString       start=/'/ end=/'/ contains=corinEscape
syn region corinInterp       start=/{/ end=/}/ contained contains=TOP
syn match  corinEscape       "\\." contained

" ── Numbers ───────────────────────────────────────────────────────────────
syn match corinNumber        "\b0[xX][0-9a-fA-F_]\+\b"
syn match corinNumber        "\b0[bB][01_]\+\b"
syn match corinNumber        "\b0[oO][0-7_]\+\b"
syn match corinNumber        "\b[0-9][0-9_]*\.[0-9][0-9_]*\([eE][+-]\?[0-9]\+\)\?\b"
syn match corinNumber        "\b[0-9][0-9_]*\b"

" ── Class / type names (PascalCase) ───────────────────────────────────────
syn match corinTypeName      "\b[A-Z][a-zA-Z0-9_]*\b"

" ── Function declarations and calls ──────────────────────────────────────
syn match corinFuncDecl      "\bfn\s\+\zs[a-zA-Z_][a-zA-Z0-9_]*"
syn match corinFuncCall      "\b[a-zA-Z_][a-zA-Z0-9_]*\ze\s*("

" ── Operators ─────────────────────────────────────────────────────────────
syn match corinOperator      "=>"
syn match corinOperator      "->"
syn match corinOperator      "<-"
syn match corinOperator      "\*\*"
syn match corinOperator      "==\|!=\|<=\|>=\|&&\|||"
syn match corinOperator      "[+\-*/%<>!&|^~=?]"

" ── Highlight links ───────────────────────────────────────────────────────
hi def link corinKeyword     Keyword
hi def link corinDeclaration Keyword
hi def link corinModifier    StorageClass
hi def link corinAsync       Keyword
hi def link corinException   Exception
hi def link corinType        Type
hi def link corinConstant    Constant
hi def link corinDecorator   PreProc
hi def link corinDocComment  SpecialComment
hi def link corinComment     Comment
hi def link corinFString     String
hi def link corinString      String
hi def link corinInterp      Special
hi def link corinEscape      SpecialChar
hi def link corinNumber      Number
hi def link corinTypeName    Type
hi def link corinFuncDecl    Function
hi def link corinFuncCall    Function
hi def link corinOperator    Operator

let b:current_syntax = "corin"
