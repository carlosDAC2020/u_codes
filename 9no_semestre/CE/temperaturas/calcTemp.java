/*
Estudiante
 - Carlos Daniel Agamez Palomino T00059006

    Descripción: 
    Crea un programa en Java que convierta temperaturas entre Celsius, Fahrenheit y Kelvin. El usuario debe poder ingresar una temperatura en una escala y seleccionar a qué escala desea convertirla.
*/
import java.util.InputMismatchException;
import java.util.Scanner;

public class calcTemp {

    // manejador de entradas desde teclado
    public static Scanner input = new Scanner(System.in);
    
    // metodo principal de ejecucion 
    public static void main(String[] args) {
        
        // manejador de solicitudes  
        boolean handlerSesion = true;
        // temperatura resultado de las converciones 
        double tempResult = 0.0;
        // flujo de ejecucvion 
        while (handlerSesion) {
            switch (menu()) {
                case 1:
                    System.out.println("------------------------------");
                    System.out.println(" Celsius -> Fahrenheit");
                    tempResult = celsiusToFahrenheit(getTemperature("Celsius"));
                    System.out.println(" Temperatura en Fahrenheit: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 2:
                    System.out.println("------------------------------");
                    System.out.println(" Fahrenheit -> Celsius");
                    tempResult = fahrenheitToCelsius(getTemperature("Fahrenheit"));
                    System.out.println(" Temperatura en Celsius: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 3:
                    System.out.println("------------------------------");
                    System.out.println(" Celsius -> Kelvin");
                    tempResult = celsiusToKelvin(getTemperature("Celsius"));
                    System.out.println(" Temperatura en Kelvin: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 4:
                    System.out.println("------------------------------");
                    System.out.println(" Kelvin -> Celsius");
                    tempResult = kelvinToCelsius(getTemperature("Kelvin"));
                    System.out.println(" Temperatura en Celsius: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 5:
                    System.out.println("------------------------------");
                    System.out.println(" Fahrenheit -> Kelvin");
                    tempResult = fahrenheitToKelvin(getTemperature("Fahrenheit"));
                    System.out.println(" Temperatura en Kelvin: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 6:
                    System.out.println("------------------------------");
                    System.out.println(" Kelvin -> Fahrenheit");
                    tempResult = kelvinToFahrenheit(getTemperature("Kelvin"));
                    System.out.println(" Temperatura en Fahrenheit: " + tempResult);
                    System.out.println("------------------------------");
                    break;
                case 7:
                    // detenemos el programa 
                    System.out.println("Hasta promto...");
                    handlerSesion = false;
                    break;
                default:
                    System.out.println("Opción no válida");
            }
        }
    }

    // Método manejador del menú
    public static int menu() {
        int option=-1;
        do{
            try{
                System.out.println("------------------------------");
                System.out.println("|  Conversor de temperaturas |");
                System.out.println("------------------------------");
                System.out.println("| 1: Celsius -> Fahrenheit   |");
                System.out.println("| 2: Fahrenheit -> Celsius   |");
                System.out.println("| 3: Celsius -> Kelvin       |");
                System.out.println("| 4: Kelvin -> Celsius       |");
                System.out.println("| 5: Fahrenheit -> Kelvin    |");
                System.out.println("| 6: Kelvin -> Fahrenheit    |");
                System.out.println("| 7: Salir                   |");
                System.out.println("------------------------------");
                System.out.print(" Selecciona una opción: ");
                option = input.nextInt();

                if (option <= 0 || option > 7) {
                    System.out.println("Valor inválida: Ingresar solo valores ubicados en el rando dispuesto (1 a 7).");
                }
        } catch (InputMismatchException e) {
            System.out.println("Valor invalido: Por favor ingresar solo valores numericos.");
            input.next();
        }
            
        }while(option<=0 || option>7);
        
        // retorno de opcion 
        return option;
    }

    // Métodos de conversión de temperatura
    public static double getTemperature(String temperature) {
        // manejador de avisos de error 
        boolean error = false;
        String stringTemp="";
        double temp = 0.0;
        do{
            try{
                System.out.print(" Temperatura en "+temperature+": ");
                // validamos la entrada del usuario para que independientemente elija "." o "," como separador de decimales el programa no c vea afectado
                stringTemp = input.next().replace(",", "."); // replazamos , por . si es necesario
                temp = Double.parseDouble(stringTemp); // y cambiamos de tipo lo ingresado a double
                if (temperature=="kelvin" && temp<0) {
                    System.out.print("Valor inválida: La escala Kelvin no puede tener valores negativos. El valor más bajo posible es 0 Kelvin (el cero absoluto) ");
                    error = true;
                }
            }catch (InputMismatchException e) {
                System.out.println("Valor invalido: Por favor ingresar solo valores numericos.");
                input.next();
            }
        }while(error);

        return temp;
    }

    // Métodos de conversión de temperatura
    public static double celsiusToFahrenheit(double celsius) { 
        return (celsius * 9/5) + 32;
    }

    public static double fahrenheitToCelsius(double fahrenheit) { 
        return (fahrenheit - 32) * 5/9;
    }

    public static double celsiusToKelvin(double celsius) { 
        return celsius + 273.15;
    }

    public static double kelvinToCelsius(double kelvin) { 
        return kelvin - 273.15;
    }

    public static double fahrenheitToKelvin(double fahrenheit) { 
        return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
    }

    public static double kelvinToFahrenheit(double kelvin) { 
        return celsiusToFahrenheit(kelvinToCelsius(kelvin));
    }

}
    


