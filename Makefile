all: dvi
dvi:
	@makeinfo --html --no-warn --no-validate --force ./manual.texi
	@cd manual; open index.html

