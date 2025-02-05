--a
use [Fabrica de ciocilata]
CREATE TABLE Departament (
	departament_id INT PRIMARY KEY,
	name VARCHAR(50),
	location VARCHAR(50),
	manager_id INT
);

CREATE TABLE Employee (
	employee_id INT,
	departament_id INT,
	position VARCHAR(50),
	hire_date DATE,
	salary FLOAT,
	inventory_id INT,
	PRIMARY KEY (employee_id, departament_id), --cheie primara compusa
	FOREIGN KEY (departament_id) REFERENCES Departament(departament_id) --cheie straina
);

--b
INSERT INTO Departament (departament_id, name, location, manager_id)
VALUES (1,'Productie', 'Bucuresi', 2),
	   (2,'Calitate si control', 'Iasi', 3),
	   (3, 'Vanzari si Marketing', 'Sibiu', 1),
	   (4,'R&D (Cercetare si dezvoltare)',' Brasov', 4),
	   (5, 'Logistica si aprovizionare', 'Cluj', 5);

INSERT INTO Employee (employee_id, departament_id, position, hire_date, salary, inventory_id)
VALUES (1, 3, 'Operator linie productie','2024-04-22', 19055, 2),
	   (2, 4, 'Tehnician mentenanta', '2017-09-15', 25388, 1 ),
	   (3, 1, 'Controlor calitate', '2019-12-08', 34002, 3 ),
	   (4, 2, 'Ambalator produse finite', '2015-03-30', 28905, 5 ),
	   (5, 5, 'Inginer de proces', '2000-07-19', 40038, 4 );

--c
INSERT INTO Employee (employee_id, departament_id, position, hire_date, salary, inventory_id)
VALUES (1, 6, 'Magazioner','2023-04-29', 15355, 1)

--d
UPDATE Employee
SET position = 'Magazioner'
WHERE employee_id = 1 AND departament_id = 1;

DELETE FROM Employee
WHERE salary IS NOT NULL;

SELECT * FROM Employee
WHERE employee_id BETWEEN 1 AND 3;

SELECT *FROM Employee
WHERE position LIKE 'A%';

Select * From Departament

Select * From Product

Select * From Inventory

Select * From Campaign

--toti angajatii de la Productie
Select * From Employee
Inner join Departament on Departament.departament_id = Employee.departament_id
Where Departament.name = 'Productie'

Select * From Customer
Inner join [Order] as ord on Customer.customer_id = [Order].[customer_id]
Inner join OrderDetails on [Order].order_id = OrderDetails.order_id
Inner join Product on OrderDetails.product_id = Product.product_id
Where Product.name = 'Ciocolata Zanelor'


--toate produsele cu mai mult de 3 furnizori care sunt, de asemenea, promovate pe o anumita platforma

Select Product.name From Product 
Inner join RawMaterial on RawMaterial.product_id = Product.product_id
Inner join Suppiler on Suppiler.raw_material_id = RawMaterial.raw_material_id
Group by Product.name
Having COUNT(Suppiler.suppiler_id) >= 1

Intersect

Select Product.name From Product
Inner join ProductAdvertisement on ProductAdvertisement.product_id = Product.product_id
Inner join Advertisement on Advertisement.ad_id = ProductAdvertisement.ad_id
Where Advertisement.platform= 'Facebook'



---- platformele de publicitate și numarul de produse pe care le-au promovat, cu excepția platformelor care au suma salariala a angajaților peste ?

Select  Advertisement.platform , COUNT(Product.product_id) as nrProducts From Advertisement
Inner join  ProductAdvertisement on ProductAdvertisement.ad_id = Advertisement.ad_id
Inner join Product on Product.product_id= ProductAdvertisement.product_id
Group by Advertisement.platform

Except

Select Advertisement.platform , COUNT(Product.product_id) as nrProducts From Advertisement
Inner join Manager on Manager.manager_id = Advertisement.manager_id
Inner join Departament on Departament.manager_id = Manager.manager_id
Inner join Employee on Employee.departament_id= Departament.departament_id
Inner join  ProductAdvertisement on ProductAdvertisement.ad_id = Advertisement.ad_id
Inner join Product on Product.product_id= ProductAdvertisement.product_id
Group by Advertisement.platform
Having SUM(Employee.salary) >= 12300
Order by nrProducts ASC


-- Returneaza toate produsele al caror pret este mai mare decat pretul mediu al tuturor produselor din stoc
Select Product.product_id, Product.name From Product
Inner join Inventory on Inventory.product_id = Product.product_id 
WHERE Product.price > (SELECT AVG(Product.price) From Product)

--Returneaza primele 5 campanii unice cu cele mai mari valori ale begetului ordonate
Select DISTINCT Top 5 Campaign.campaign_id, Campaign.buget From Campaign
Order by Campaign.buget DESC

--Selecteaza produsele care au un pret mai mic de 50 si produsele care nu sunt disponibile in stoc
Select Product.product_id, Product.name From Product
Where Product.price < 50
Union
Select Product.product_id, Product.name From Product
Where Product.product_id IN ( Select Inventory.product_id From Inventory Where Inventory.quantity= 0)

--Selectează produsele care nu au stocuri mai mici decât toate cantitățile disponibile în inventar pentru acele produse.
Select Product.name From Product
Inner join Inventory on Inventory.product_id = Product.product_id
Where Product.product_id NOT IN (
 Select Inventory.product_id from Inventory
 Where Inventory.quantity < ALL ( Select quantity from Inventory Where product_id= Product.product_id) 
 )

 --Selectează furnizorii care au produse cu un preț mai mic decât oricare dintre prețurile produselor din categoria "1"
 Select Suppiler.name From Suppiler
 Inner join RawMaterial on RawMaterial.suppiler_id= Suppiler.suppiler_id
 Inner join Product on Product.product_id = RawMaterial.product_id
 Where Suppiler.suppiler_id IN (
 Select Product.product_id from Product
 Where Product.price < ANY ( Select Product.price From Product Where Product.category = 1)
 )

 --Selectează angajații care au o anumita pozitie
 Select Employee.name from Employee
 Where Employee.position IN ('Manager', 'Inginer de proces')

 --Această interogare selectează produsele și cantitatea din inventar pentru produsele care au un stoc mai mic de 10 sau care aparțin oricărei descrieri ce începe cu ...
 Select Product.name from Product
 LEFT JOIN Inventory on Product.product_id = Inventory.product_id
 Where Inventory.quantity < 10 OR Product.category IN ( Select category from Product Where category = 1)
