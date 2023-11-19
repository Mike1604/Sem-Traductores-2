
# Analizador Semantico

Esta parte del repositorio corresponde al analizador Semantico el cual cuenta con una tabla de variables y una tabla de funciones donde podemos ver las variables y las funciones declaradas previamente, asimismo hace uso del ya anteriormente usado analizador lexico y analizados sintactico los cuales brindan las herramientas para que este analizador Semantico pueda trabajar.
## Compilador
La siguiente imagen corresponde al compilador en el momento del Analizador Semantico
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura.JPG?raw=true)
## Semantico
La siguiente imagen corresponde al apartado del analizador Sintactico, en el cual podemos ver primero ingresamos el programa a evaluar una vez hecho esto podemos ver el arbol sintactico:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura2.JPG?raw=true)

## 1er Ejemplo
El primer ejemplo que se realizo se introdujo la siguiente cadena:
La cual se analiza lexicamente y posteriormente se realiza el analisis Sintactico y al final el analisis semantico como podemos ver a continuacion, donde vemos las variables y funciones que son parte de dicho codigo:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura3.JPG?raw=true)
## 2do Ejemplo
El 2d0 ejemplo que se realizo se introdujo una cadena mas compleja la cual es la siguiente:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura4.JPG?raw=true)
La cual se analiza lexicamente y posteriormente se realiza el analisis Sintactico, podemos ver su arbol sintactico a continuacion:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura5.JPG?raw=true)
Despues podemos ver el apartado del analisis semantico donde podemos ver que tenemos todas las variabels y funciones que estan dentro de este, asi como los parametros de las funciones y el ambito de las variables:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura6.JPG?raw=true)

De igual manera con el ejemplo anterior en caso de que ingresaramos un programa donde ingresemos mas de una variable con el mismo nombre o funcion, donde estemos realizando la reasignacion, este nos avisara con un warning como podemos ver a continuacion:

![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura7.JPG?raw=true)

![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Semantico/ImagenesReadme/Captura8.JPG?raw=true)



