import pandas as pd


try:
    # Leer el archivo CSV
    df = pd.read_csv("inventario.csv", delimiter=';', on_bad_lines='skip')
except Exception as e:
    print(f"Error al leer el archivo CSV: {e}")
else:
    # Mostrar información del DataFrame original
    print("Información del DataFrame original:")
    print(df.info())
    
    # Contar las filas con valores nulos en el DataFrame original
    total_nulos = df.isnull().sum().sum()  # Suma de todos los valores nulos
    total_filas_nulas = df.isnull().any(axis=1).sum()  # Cantidad de filas con al menos un valor nulo
    print(f"Total de valores nulos en el DataFrame: {total_nulos}")
    print(f"Total de filas con al menos un valor nulo: {total_filas_nulas}")

    # Eliminar filas completamente vacías
    df_cleaned = df.dropna(how='all').copy()

    # Mostrar información del DataFrame después de eliminar filas completamente vacías
    print("\nInformación del DataFrame después de eliminar filas completamente vacías:")
    print(df_cleaned.info())

    # Contar la cantidad de fechas con formato incorrecto antes de la conversión
    if 'Fecha' in df_cleaned.columns:
        # Eliminar caracteres no válidos y contar fechas incorrectas
        df_cleaned['Fecha_limpia'] = df_cleaned['Fecha'].str.replace(r'[^\d/]', '', regex=True)
        incorrect_format_dates_before = df_cleaned['Fecha_limpia'].str.match(r'\d{1,2}/\d{1,2}/\d{4}').sum()
        print(f"Total de fechas con formato incorrecto antes de la conversión: {len(df_cleaned) - incorrect_format_dates_before}")

    # Limpiar la columna de 'Fecha' y convertirla al formato datetime
    if 'Fecha' in df_cleaned.columns:
        # Eliminar caracteres no válidos y convertir la columna de fecha
        df_cleaned['Fecha'] = df_cleaned['Fecha'].str.replace(r'[^\d/]', '', regex=True)
        df_cleaned['Fecha'] = pd.to_datetime(df_cleaned['Fecha'], format='%d/%m/%Y', errors='coerce')

    # Volver a contar la cantidad de fechas con formato incorrecto después de la conversión
    if 'Fecha' in df_cleaned.columns:
        incorrect_format_dates_after = df_cleaned['Fecha'].isna().sum()
        print(f"Total de fechas con formato incorrecto después de la conversión: {incorrect_format_dates_after}")

    # Opcional: guardar el DataFrame limpio a un nuevo archivo Excel
    df_cleaned.to_excel("Inventario_limpio.xlsx", index=False)

    # Mostrar información del DataFrame limpio
    print("\nInformación del DataFrame limpio:")
    print(df_cleaned.info())
