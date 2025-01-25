# Importa la biblioteca qrcode. Instálala con "pip install qrcode[pil]" si no la tienes.
import qrcode

def generar_codigos_qr(codigos_barras):
    """
    Genera y guarda un código QR para cada código de barras en la lista codigos_barras.
    
    Parámetros:
    - codigos_barras (list): Lista de códigos de barras (ID de productos) para los que se generará un QR.
    """
    for codigo in codigos_barras:
        # Crea el código QR a partir del código de barras
        qr = qrcode.make(codigo)
        
        # Define el nombre del archivo usando el código de barras
        nombre_archivo = f"{codigo}.png"
        
        # Guarda el código QR como archivo PNG
        qr.save(nombre_archivo)
        
        # Mensaje de confirmación
        print(f"Código QR para '{codigo}' guardado como: {nombre_archivo}")

# Lista de códigos de barra o ID de productos
codigos_barras = ["214758", "472945", "945373", "745361", "436745"]

# Genera y guarda los códigos QR
generar_codigos_qr(codigos_barras)