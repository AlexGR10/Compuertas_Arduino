/* Entrada del display */
int a =2;
int b =3;
int c =4;
int d =5;
int e =6;
int f =7;
int g =8;
/* Ledes */
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int bandera=13;
/* Variable para el menú */
int opc;
int num1, num2, resultado;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); /* Activamos el serial */
  /* MENÚ */
  Serial.println("Selecciona la operación que deseas");
  Serial.println("0: Suma");
  Serial.println("1: Resta");
  Serial.println("2: División");
  Serial.println("3: Multiplicación");
  Serial.println("4: Compuerta lógica AND");
  Serial.println("5: Compuerta lógica OR");
  Serial.println("6: Compuerta lógica XOR");
  Serial.println("7: Compuerta lógica NOT");


/* Modo de pines */
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(bandera, OUTPUT);

 while(!Serial); /* Se activa el serial */

}

void loop() {
 
  Serial.println("Ingrese la operación ");
  while(Serial.available() == 0);
  opc = Serial.read();
  eleccion1(opc);

}


void eleccion1(int opc){
int num1, num2, resultado;
switch (opc) {
  case '1':
  digitalWrite(led1, HIGH); /* Prende un led de la suma */
  Serial.println("Haz elejido la suma");
  delay(5000);
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  Serial.println(num2);
  delay(5000); /* Segundo número */

if(num1 == 00 && num2 == 00){ /* Resultado 0 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);

} /* Fin del primer if */
else if (num1 == 00 && num2 == 01 || num1 == 01 && num2 == 00)   { /* Resultado 1 */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
else if (num1 == 00 && num2 == 10 || num1 == 01 && num2 == 01) { /* Resultado 2 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
else if( num1 == 00 && num2 == 11 || num1 == 01 && num2 == 10 || num1 == 11 && num2 == 00 || num1 == 01 && num2 == 11 )  { /* Resultado 3 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(led1, HIGH);
}
else if (num1 == 01 && num2 == 11 || num1 == 10 && num2 == 10 || num1 == 11 && num2 == 01){ /* Resultado 4 */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
else if (num1 == 10 && num2 == 11 ){ /* resultado 5 */
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

}
digitalWrite(led1, LOW);
break ; /* fin del caso 1 */

case '2':
digitalWrite(led2, HIGH); /* Prende un led de la resta */
  Serial.println("Haz elejido la resta");
  delay(5000);
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(5000); /* Segundo número */
   Serial.println(num2);

if(num1 == 00 && num2 == 00){ /* Resultado 0 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);

} 
else if (num1 == 00 && num2 == 01 || num1 == 01 && num2 == 00){ /* Resutaldo -1 */
  digitalWrite(bandera, HIGH); /* Bandera para negativos y otras cosas */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
} /* Fin del if 1 */
else if (num1 == 00 && num2 == 10 || num1 == 01 && num2 == 11 ){ /* Resultado -2 */
  digitalWrite(bandera, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
} /* Fin del dos */

else if (num1 == 00 && num2 == 11){ /* Resultado -3 */
  digitalWrite(bandera, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

else if (num1 == 01 && num2 == 00 || num1 == 10 && num2 == 01){/* Resultado + 1  */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
} /* Fin */
else if (num1 == 10 && num2 == 00 ){ /* Resultado +2 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
else if (num1 == 11 && num2 == 00 ){ /* Resultado +3 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
delay(5000);
/* digitalWrite(led2, LOW); */
  break;

  case '3':
  digitalWrite(led3, HIGH); /* Prende un led de la división */
  Serial.println("Haz elejido la división");
  delay(5000);
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(5000); /* Segundo número */
   Serial.println(num2);

  if (num1 == 00 && num2 == 00){/* Resultado 0 con mega error */
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(bandera, HIGH);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
delay(10000);
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(bandera, HIGH);

  }
else if (num1 == 00 && num2 == 01 || num1 == 00 && num2 == 10 || num1 == 00 && num2 == 11 || num1 == 01 && num2 == 10 || num1 == 01 && num2 == 11 || num1 == 10 && num2 == 11){ /* Resultado 0 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
else if (num1 == 01 && num2 == 00 || num1 == 01 && num2 == 01 || num1 == 10 && num2 == 01 || num1 == 10 && num2 == 10 || num1 == 11 && num2 == 00 || num1 == 11 && num2 == 01){ /* Resultado 1 */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
else if (num1 == 10 && num2 == 00 ){ /* Resultado 2 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  
}
  break;

  case '4':
  digitalWrite(led4, HIGH); /* Led de multiplicación */
Serial.println("Haz elejido la multiplicación");
  delay(5000);
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(5000); /* Segundo número */
   Serial.println(num2);

  if (num1 == 00 && num2 == 00 || num1 == 00 && num2 == 01 ||num1 == 00 && num2 == 10 || num1 == 00 && num2 == 11 || num1 == 01 && num2 == 00){ 
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  } /* Da cero */
  else if (num1 == 01 && num2 == 01){ /* Da 1 */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);  
  }
  else if (num1 == 01 && num2 == 10 || num1 == 10 && num2 == 01){ /* Da 2 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  }
  else if (num1 == 11 && num2 == 00 || num1 == 11 && num2 == 01){ /* Da 3 */
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  }
  else if (num1 == 10 && num2 == 10){ /* Da 4 */
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  }
 /*  digitalWrite(led4, LOW); */
  break; /* Fin del case 4 */
case '5':

  Serial.println("Ahora vamos con las compuertas lógicas, apagando display");
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(4000);
  Serial.println("Ahora usamos los ledes");
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(4000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  Serial.println("Soy la AND");
  delay(5000);
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(5000); /* Segundo número */
   Serial.println(num2);


  if(num1 == 11 && num2 == 11){
    digitalWrite(led1, HIGH);
  }
  else {
    Serial.println("Solo si todos son 1 pasa sino no");
  }
  break;
  case '6': 
   digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
 Serial.println("Ahora usamos los ledes soy la OR");
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(5000); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(5000); /* Segundo número */
   Serial.println(num2);
if(num1 == 01 || num2 == 00 || num1 == 10 || num2 == 10 || num1 == 11 || num2 == 11){
    digitalWrite(led2, HIGH);
  }
  break;
  case '7':
   digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  Serial.println("Ahora usamos los ledes soy la XOR");
  Serial.println("Ingrese el primer número binario:");
  while (Serial.available() == 0);
  num1 = Serial.parseInt();
    delay(100); /* Primer número */
  Serial.println(num1);

  Serial.println("Ingrese el segundo número binario:");
  while (Serial.available() == 0);
  num2 = Serial.parseInt();
  delay(100); /* Segundo número */
   Serial.println(num2);
if(num1 == 11 && num2 == 11){
    digitalWrite(led3, HIGH);
  }else{
    digitalWrite(led2, HIGH);
  }
   break;
  case '8':
   digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  Serial.println("Ahora usamos los ledes soy la NOT");
  digitalWrite(led4, HIGH);
break;
  } /* Fin del switch */

} /* Fin de mi funcion */
