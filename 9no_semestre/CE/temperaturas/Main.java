//Adriana Carolina Mastrascusa González
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int parar = 0;
        Scanner leer = new Scanner(System.in); //Se escanea la consola
        leer.useLocale(Locale.US); // Configura el scanner para usar el punto como separador decimal

        //Se hace un ciclo while para que el usuario tenga la opción de realizar múltiples conversiones
        while (true) {

            //se hace la impresión del menú, por eso está como salida
            System.out.println("Convertidor de Temperatura");
            System.out.println("¿Qué conversión desea realizar?:");
            System.out.println("1) Temperatura Celsius -> Temperatura Fahrenheit");
            System.out.println("2) Temperatura Celsius -> Temperatura Kelvin");
            System.out.println("3) Temperatura Fahrenheit -> Temperatura Celsius");
            System.out.println("4) Temperatura Fahrenheit -> Temperatura Kelvin");
            System.out.println("5) Temperatura Kelvin -> Temperatura Celsius");
            System.out.println("6) Temperatura Kelvin -> Temperatura Fahrenheit");
            System.out.println("7) Salir del programa");

            //El comando try-catch se usa para que el programa pueda seguir funcionando aunque se ingrese una entrada incorrecta.
            try {
                System.out.print("Elija una opción del 1 al 7: ");
                int eleccion = leer.nextInt(); //Lo que está en leer, se guarda en la variable de tipo entero "eleccion" y esa es la variable a trabajar para la elección de la conversión.

                if (eleccion == 7) {
                    System.out.println("Programa finalizado.");
                    return;
                }
                //Se parametriza para que se quede el código se termine en caso tal se ingrese una opción que se encuentre por fuera establecidas.
                if (eleccion <=0 || eleccion > 7) {
                    System.out.println("Opción no encontrada.");
                    return;
                }

                //Se hace el ingreso de la temperatura a la cual se le desea realizar la conversión escogida.
                System.out.print("Por favor, ingrese el valor de la temperatura: ");
                double valor_t = leer.nextDouble();
                double operacion;
                String resultado_operacion = "";

                //Estructura de control en la cual se podrán realizar las diferentes conversiones dependiendo de lo guardado en la variable eleccion.
                switch (eleccion) {
                    case 1:
                        operacion = (valor_t) * 9 / 5 + 32;
                        resultado_operacion = String.format(Locale.US,"%.2f grados Celsius son %.2f grados Fahrenheit.", valor_t, operacion);
                        break;

                    case 2:
                        if (valor_t < -273.5) {
                            System.out.println("Ingresa una temperatura mayor que -273.5");
                        } else {
                            operacion = (valor_t) + 273.15;
                            resultado_operacion = String.format(Locale.US,"%.2f grados Celsius son %.2f Kelvin.", valor_t, operacion);
                        }
                        break;

                    case 3:
                        operacion = (valor_t - 32) * 5 / 9;
                        resultado_operacion = String.format(Locale.US, "%.2f grados Fahrenheit son %.2f grados Celsius.", valor_t, operacion);
                        break;

                    case 4:

                        operacion = (valor_t - 32) * 5 / 9 + 273.15;
                        resultado_operacion = String.format(Locale.US, "%.2f grados Fahrenheit son %.2f Kelvin.", valor_t, operacion);
                        break;

                    case 5:
                        if (valor_t < 0) {
                            System.out.println("Ingresa una temperatura mayor que 0.");
                        } else {
                            operacion = (valor_t) - 273.15;
                            resultado_operacion = String.format(Locale.US, "%.2f Kelvin son %.2f grados Celsius.", valor_t, operacion);
                        }
                        break;

                    case 6:
                        if (valor_t < 0) {
                            System.out.println("Ingresa una temperatura mayor que 0.");
                        } else {
                            operacion = (valor_t - 273.15) * 9 / 5 + 32;
                            resultado_operacion = String.format(Locale.US, "%.2f Kelvin son %.2f grados Fahrenheit.", valor_t, operacion);

                        }
                        break;
                }
                //Se imprime el resultado de la conversion.
                System.out.println(resultado_operacion);

                // Se valida si el usuario quiere seguir realizando conversiones o si desea salir del programa.
                System.out.println("¿Quiere seguir en el programa? \n Si  = 1 \n No = 0");
                parar = leer.nextInt();
                if (parar == 0) {
                    System.out.println("Programa finalizado.");
                    break;
                }

            } catch (InputMismatchException e) {
                System.out.println("Existe un error en el dato ingresado, solo se pueden ingresar números y valores en decimales con punto.");
                leer.next();
            }

        }
    }
}