# Corin Editor Support

Syntax highlighting for Corin (`.corin`) across all major editors.

## VSCode

The extension lives in `editors/vscode/`. It provides:
- Syntax highlighting
- LSP (autocomplete, go-to-definition, find references, diagnostics)
- Debug adapter

**Install (one command):**
```bash
code --install-extension editors/vscode/corin-lang.vsix
```

Or build and install the latest yourself:
```bash
cd editors/vscode
npx @vscode/vsce package --no-dependencies
code --install-extension corin-lang-*.vsix
```

Then reload VSCode (`Ctrl+Shift+P` → "Reload Window").

---

## Vim / Neovim

**Install (manual):**
```bash
mkdir -p ~/.vim/syntax ~/.vim/ftdetect
cp editors/vim/syntax/corin.vim ~/.vim/syntax/
cp editors/vim/ftdetect/corin.vim ~/.vim/ftdetect/
```

**Install (vim-plug):**
```vim
Plug 'corin-lang/corin-vim'
```

**Install (lazy.nvim):**
```lua
{ 'corin-lang/corin-vim' }
```

---

## Sublime Text

Copy the syntax file to your Sublime Text packages:
```bash
# macOS
cp editors/sublime/Corin.sublime-syntax \
   ~/Library/Application\ Support/Sublime\ Text/Packages/User/

# Linux
cp editors/sublime/Corin.sublime-syntax \
   ~/.config/sublime-text/Packages/User/
```

---

## Nano

```bash
cp editors/nano/corin.nanorc ~/.config/nano/
echo 'include "~/.config/nano/corin.nanorc"' >> ~/.nanorc
```

---

## Emacs

```elisp
(add-to-list 'load-path "/path/to/editors/emacs")
(require 'corin-mode)
```

Or with `use-package`:
```elisp
(use-package corin-mode
  :load-path "path/to/editors/emacs")
```

---

## What's highlighted

| Token | Example |
|---|---|
| Keywords | `if`, `fn`, `class`, `match`, `async` |
| Types | `int`, `str`, `bool`, `Vec`, `Option` |
| Constants | `true`, `false`, `none`, `Ok`, `Err` |
| Strings | `"hello"`, `'world'` |
| F-strings | `f"Hello {name}"` |
| Doc comments | `/// This is a doc comment` |
| Comments | `# regular comment` |
| Decorators | `@cache`, `@timing` |
| Numbers | `42`, `3.14`, `0xFF`, `0b1010` |
| Operators | `=>`, `->`, `<-`, `**`, `?` |
| Function names | `fn greet(...)` |
| Type names | `class Dog`, `trait Animal` |
