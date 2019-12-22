segment .data
	msg_error db "Error en el programa" , 0
	msg_rango db "Indice de vector fuera de rango" , 0
	error_div0 db "Error al dividir entre 0", 0
segment .bss
	__esp resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
	_x resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	resultado
	_resultado resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
segment .text 
	global main 
	extern scan_int, scan_boolean, print_int, scan_float, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::=
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	res2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_fibonacci: 
	push ebp 
	mov ebp, esp 
	sub esp, 8 
;D:	(
;D:	(
;D:	num1
;D:	==
	lea eax, [ebp - 8] 
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 0 
;R81:	<exp> ::= <constante>
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,edx
	je near igual0
	push dword 0
	jmp near fin_igual0
igual0:
	push dword 1
fin_igual0:
;R93:	<comparacion> ::= <exp> == <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop eax 
	cmp eax,0
	je near fin_then0 
;D:	return
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 0 
;R81:	<exp> ::= <constante>
;D:	;
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse0 
fin_then0:
;D:	if
fin_ifelse0: 
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	num1
;D:	==
	lea eax, [ebp - 8] 
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 1 
;R81:	<exp> ::= <constante>
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,edx
	je near igual1
	push dword 0
	jmp near fin_igual1
igual1:
	push dword 1
fin_igual1:
;R93:	<comparacion> ::= <exp> == <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop eax 
	cmp eax,0
	je near fin_then1 
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 1 
;R81:	<exp> ::= <constante>
;D:	;
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
	jmp near fin_ifelse1 
fin_then1:
;D:	res1
fin_ifelse1: 
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
	lea eax, [ebp - 8] 
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 1 
;R81:	<exp> ::= <constante>
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	sub eax, edx
	push dword eax
;R73:	<exp> ::= <exp> - <exp>
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci 
	add esp, 4
	push dword eax 
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
;D:	;
	lea eax ,[ebp + 4] 
	push dword eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	res2
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
	lea eax, [ebp - 8] 
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
	push dword 2 
;R81:	<exp> ::= <constante>
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	sub eax, edx
	push dword eax
;R73:	<exp> ::= <exp> - <exp>
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci 
	add esp, 4
	push dword eax 
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
;D:	;
	lea eax ,[ebp + 0] 
	push dword eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	return
;D:	res1
;D:	+
	lea eax, [ebp - -4] 
	push dword eax
;R80:	<exp> ::= <identificador>
;D:	res2
;D:	;
	lea eax, [ebp - -8] 
	push dword eax
;R80:	<exp> ::= <identificador>
	pop dword eax
	pop dword edx
	mov dword edx, [edx]
	mov dword eax, [eax]
	add eax, edx
	push dword eax
;R72:	<exp> ::= <exp> + <exp>
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R22 :	<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) { <declaraciones_funcion> <sentencias> }
;D:	scanf
;R21:	<funciones> ::=
;R20:	<funciones> ::= <funcion> <funciones>
main: 
	mov dword [__esp], esp ; Guarda el puntero de la pila 
;D:	x
	push dword _x
	call scan_int
	add esp, 4
;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	fibonacci
;D:	(
;D:	x
;D:	)
	push dword _x 
;R80:	<exp> ::= <identificador>
	pop dword eax 
	mov dword eax, [eax]
	push dword eax 
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci 
	add esp, 4
	push dword eax 
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
;D:	;
	pop eax
	mov [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
	push dword _resultado 
;R80:	<exp> ::= <identificador>
	pop dword eax
	mov dword eax,[eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
	jmp fin
fin_div0: 
	push dword error_div0
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
fin_error: 
	push dword msg_error
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
fin:
	mov dword esp, [__esp]
	ret
fin_indice_fuera_rango: 
	push dword msg_rango
	call print_string
	add esp, 4
	call print_endofline
	jmp fin
