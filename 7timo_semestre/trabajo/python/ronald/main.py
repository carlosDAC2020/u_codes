class Product:
    def __init__(self, product_id, name, description, unit_price, available_quantity):
        self.product_id = product_id
        self.name = name
        self.description = description
        self.unit_price = unit_price
        self.available_quantity = available_quantity

    def display_product_info(self):
        print(f"Product ID: {self.product_id}")
        print(f"Name: {self.name}")
        print(f"Description: {self.description}")
        print(f"Unit Price: ${self.unit_price}")
        print(f"Available Quantity: {self.available_quantity} units")


products = []


def add_product():
    product_id = int(input("Enter product ID: "))
    name = input("Enter product name: ")
    description = input("Enter product description: ")
    unit_price = float(input("Enter unit price: "))
    available_quantity = int(input("Enter available quantity: "))

    new_product = Product(product_id, name, description, unit_price, available_quantity)
    products.append(new_product)
    print("Product added successfully.")


def delete_product():
    product_id = int(input("Enter the product ID to delete: "))
    for product in products:
        if product.product_id == product_id:
            products.remove(product)
            print(f"Product with ID {product_id} deleted successfully.")
            return
    print(f"Product with ID {product_id} not found.")


def update_product():
    product_id = int(input("Enter the product ID to update: "))
    for product in products:
        if product.product_id == product_id:
            product.name = input("Enter new product name: ")
            product.description = input("Enter new product description: ")
            product.unit_price = float(input("Enter new unit price: "))
            product.available_quantity = int(input("Enter new available quantity: "))
            print(f"Product with ID {product_id} updated successfully.")
            return
    print(f"Product with ID {product_id} not found.")


def see_list_product():
    if not products:
        print("No products in the list.")
    else:
        for product in products:
            product.display_product_info()
            print("------------------------")


def main():
    print("que decea hacer ?")
    print("1 -> añadir producto")
    print("2 -> eliminar producto")
    print("3 -> actualizar producto")
    print("5 -> mostrar lista de producto")

    op=int(input(" ingrese el valor correspondiente (1 a 5):"))

    while op<1 or op >5:
        print("ingrese un valor valido")
        op=int(input(" ingrese el valor correspondiente (1 a 5):"))

    if op==1:
        add_product()
    elif op==2:
        delete_product()
    elif op==3:
        update_product()
    elif op==5:
        see_list_product()
    else:
        pass

main()  