
import java.util.List;

public class test {

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

    public static void main(String[] args) {
        List<Double> celsiusTemps = List.of(-273.15, 0.0, 100.0, 37.0);
        List<Double> fahrenheitTemps = List.of(-459.67, 32.0, 212.0, 98.6);
        List<Double> kelvinTemps = List.of(0.0, 273.15, 373.15, 310.15);

        System.out.println("Prueba de conversiones Celsius -> Fahrenheit:");
        for (double temp : celsiusTemps) {
            System.out.println("Celsius: " + temp + " -> Fahrenheit: " + celsiusToFahrenheit(temp));
        }

        System.out.println("\nPrueba de conversiones Fahrenheit -> Celsius:");
        for (double temp : fahrenheitTemps) {
            System.out.println("Fahrenheit: " + temp + " -> Celsius: " + fahrenheitToCelsius(temp));
        }

        System.out.println("\nPrueba de conversiones Celsius -> Kelvin:");
        for (double temp : celsiusTemps) {
            System.out.println("Celsius: " + temp + " -> Kelvin: " + celsiusToKelvin(temp));
        }

        System.out.println("\nPrueba de conversiones Kelvin -> Celsius:");
        for (double temp : kelvinTemps) {
            System.out.println("Kelvin: " + temp + " -> Celsius: " + kelvinToCelsius(temp));
        }

        System.out.println("\nPrueba de conversiones Fahrenheit -> Kelvin:");
        for (double temp : fahrenheitTemps) {
            System.out.println("Fahrenheit: " + temp + " -> Kelvin: " + fahrenheitToKelvin(temp));
        }

        System.out.println("\nPrueba de conversiones Kelvin -> Fahrenheit:");
        for (double temp : kelvinTemps) {
            System.out.println("Kelvin: " + temp + " -> Fahrenheit: " + kelvinToFahrenheit(temp));
        }
    }
}
