product_details = {
    "product1": {"size": "small", "price": 100},
    "product2": {"size": "medium", "price": 20},
    "product3": {"size": "large", "price": 300}
}

context = {"current_product": None}

print("Hi! I am chatbot. How can i assisst you?")

while True:
    user_input = input("User: ").lower()

    if "products" in user_input:
        print("Here are the available products")
        for product, details in product_details.items():
            print(product, ": ", details)
        context["current_product"] = None

    elif "size" in user_input:
        if(context["current_product"] == None):
            print("Specify the product")
        else:
            current_product = context["current_product"]
            print("The size of ", current_product, " is ", product_details[current_product]["size"])
    
    elif "price" in user_input:
        if(context["current_product"] == None):
            print("Specify the product")
        else:
            current_product = context["current_product"]
            print("The price of ", current_product, " is ", product_details[current_product]["size"])

    else:
        for product, details in product_details.items():
            if product in user_input:
                print(product, ": ", details)
                context["current_product"] = product
            break
        else:
            print("I dont understand")

    if(user_input == "exit"):
        print("bye")
        break