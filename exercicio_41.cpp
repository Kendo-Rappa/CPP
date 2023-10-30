inicio
	lógico: X;//0-1
	inteiro: Y;// =0
	Y <- 0;
	X <- falso;//1-0
	enquanto Y <> 6 faça //0 ate 6
		X <- não X;//!= 1-0 (0-1)
		Y <- Y + 1;// y+= 1
		se X// x=1
			então imprima (Y);
			senão imprima (-Y);
		fimse;
	fimenquanto;
fim.

// isso vai imprimir alguma coisa, certamente
/*O programa imprimirá os seguintes valores para o usuário:

1
-2
3
-4
5
-6*/