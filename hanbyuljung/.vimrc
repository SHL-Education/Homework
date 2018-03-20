set number
set softtabstop=4
set autoindent
syntax on
set cindent
set title
set smartindent
set autoindent
set ts=4
set hlsearch
set sw=4


set tags=/home/jhb/kernel/linux-4.4/tags
if version >= 500
func! Sts()
	let st = expand("<cword>")
	exe "sts".st
endfunc
nmap ,st :call Sts()<cr>
func! Tj()
	let st = expand("<cword>")
	exe "tj".st
endfunc
nmap ,tj :call Tj()<cr>
endif


 "cscope 설정"

set csprg=/usr/bin/cscope
set nocsverb
cs add /home/jhb/kernel/linux-4.4/cscope.out
set csto=0
set cst
func! Css()
	let css = expand("<cword>")
	new
	exe "cs find s".css
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,css :call Css()<cr>
func! Csd()
	let csd = expand("<cword>")
	new
	exe "cs find d".csd
	if getline(1) ==""
			exe "q!"
	endif
endfunc
nmap ,csd :call Csd()<cr>

func! Csg()
	let csg = expand("<cword>")
	new
	exe "cs find g".csg
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,csg :call Csg()<cr>
















