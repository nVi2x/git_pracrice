
car_names_prices = [("Deveste eight", 1795000), ("Vamos", 596000), ("Deviant", 512000), ("Schlagen GT", 1300000), 
("Tulip", 718000), ("Itali GTO", 1965000), ("Toros", 498000), ("Neon", 1500000), ("Entity XXR", 2305000), 
("Flash GT", 1675000)]

car_names_sorted = sorted(car_names_prices)

cars_u_can_buy = []

def cars_can_buy(max_price):
    for prices in car_names_sorted:
        if max_price <= prices:
            cars_u_can_buy.append(car_names_sorted[:1])
    return cars_u_can_buy
    
print(cars_can_buy(1000000))