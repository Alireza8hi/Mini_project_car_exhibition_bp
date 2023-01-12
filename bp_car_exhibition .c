#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
//------------------------------------------------------------------structs-----------------------------------------------------------------------------------------------
struct Cars {
	char name[50];
	char brand[50];
	char model[50];
	int year_of_production;
	char color[50];
	int chassis_number;
	char fuel_model[50];
	char function[50];
	int buying_price;
	int selling_price;
}cars[1000000];
struct System {
	int max_car;
	int num_of_cars;
}system;
//------------------------------------------------------------------functions---------------------------------------------------------------------------------------------
void read_file()
{
	FILE* data1 = fopen("database1.txt", "r+");
	FILE* data2 = fopen("database2.txt", "r+");
	if (data1 == NULL)
	{
		system.max_car = -1;
		system.num_of_cars = 0;
	}
	else
	{
		fread(&system, sizeof(struct System), 1, data1);
		fclose(data1);

		for (int i = 0; i < 1000000; i++)
		{
			fread(cars + i, sizeof(struct Cars), 1, data2);
		}
		fclose(data2);
	}
	return;
}
void write_file()
{
	FILE* update1 = fopen("database1.txt", "w");
	fwrite(&system, sizeof(struct System), 1, update1);
	fclose(update1);
	FILE* updata2 = fopen("database2.txt", "w");
	for (int i = 0; i < 1000000; i++)
	{
		fwrite(cars + i, sizeof(struct Cars), 1, updata2);
	}
	fclose(updata2);
	return;
}
void add_car()
{
	if (system.max_car == system.num_of_cars)
	{
		printf("the Car exhibition is full\nyou can not add a new car\n\n----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		printf("enter name of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", cars[system.num_of_cars].name);
		printf("enter brand of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", cars[system.num_of_cars].brand);
		printf("enter model of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", cars[system.num_of_cars].model);
		printf("enter year of priduction of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &cars[system.num_of_cars].year_of_production);
		printf("enter coloe of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", cars[system.num_of_cars].color);
		printf("enter chassis number of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &cars[system.num_of_cars].chassis_number);
		printf("enter fuel model of your car\n\n");
		scanf("%s", cars[system.num_of_cars].fuel_model);
		printf("enter function of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", cars[system.num_of_cars].function);
		printf("enter buying price of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &cars[system.num_of_cars].buying_price);
		printf("enter selling price of your car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &cars[system.num_of_cars].selling_price);
		system.num_of_cars++;
		printf("add car was succesfull\n\n----------------------------------------------------------------------------------------------------\n");
	}
	return;
}
int find_car(int chassis_number)
{
	int number_car = -1;
	for (int counter = 0; counter < system.num_of_cars; counter++)
	{
		if (cars[counter].chassis_number == chassis_number)
		{
			number_car = counter;
		}
	}
	return number_car;
}
void edit_car()
{
	if (system.num_of_cars == 0)
	{
		printf("there is not any cars\n\n----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		int chassis_number;
		printf("enter the chassis number to see details of car\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &chassis_number);
		int number_car = find_car(chassis_number);
		if (number_car == -1)
		{
			printf("this chassis number is not available\n\n----------------------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("name: %s\nmodel: %s\nyear of production: %d\ncolor: %s\nchassis number: %d\nfuel type: %s\nfunction: %s\nbuying price: %d\nselling price: %d\nbrand: %s\n\n", cars[number_car].name, cars[number_car].model, cars[number_car].year_of_production, cars[number_car].color, cars[number_car].chassis_number, cars[number_car].fuel_model, cars[number_car].function, cars[number_car].buying_price, cars[number_car].selling_price, cars[number_car].brand);
			printf("for edit, enter number of part\n1-name\n2-model\n3-year of production\n4-color\n5-chassis number\n6-fuel type\n7-function\n8-buying price\n9-selling price\n10-brand\n\n----------------------------------------------------------------------------------------------------\n");
			int enter;
			scanf("%d", &enter);
			if (enter == 1)
			{
				printf("enter new name\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].name);
				printf("succesfull\n\n");
			}
			else if (enter == 2)
			{
				printf("enter new model\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].model);
				printf("succesfull\n\n");
			}
			else if (enter == 3)
			{
				printf("enter new year of production\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%d", &cars[number_car].year_of_production);
				printf("succesfull\n\n");
			}
			else if (enter == 4)
			{
				printf("enter new color\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].color);
				printf("succesfull\n\n");
			}
			else if (enter == 5)
			{
				printf("enter new chassis number\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%d", &cars[number_car].chassis_number);
				printf("succesfull\n\n");
			}
			else if (enter == 6)
			{
				printf("enter new fuel model\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].fuel_model);
				printf("succesfull\n\n");
			}
			else if (enter == 7)
			{
				printf("enter new function\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].function);
				printf("succesfull\n\n");
			}
			else if (enter == 8)
			{
				printf("enter new buying price\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%d", &cars[number_car].buying_price);
				printf("succesfull\n\n");
			}
			else if (enter == 9)
			{
				printf("enter new selling price\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%d", &cars[number_car].selling_price);
				printf("succesfull\n\n");
			}
			else if (enter == 10)
			{
				printf("enter new brand\n\n----------------------------------------------------------------------------------------------------\n");
				scanf("%s", cars[number_car].brand);
				printf("succesfull\n\n");
			}
		}
	}
	return;
}
int sum_special_brand_cars(char brand[50])
{
	int sum_of_special_brand_cars = 0;
	for (int counter = 0; counter < system.num_of_cars; counter++)
	{
		if (strcmp(cars[counter].brand, brand) == 0)
		{
			sum_of_special_brand_cars++;
		}
	}
	return sum_of_special_brand_cars;
}
void report_special_brand_cars()
{
	if (system.num_of_cars == 0)
	{
		printf("there is not any cars\n\n----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		char brand[50];
		printf("enter brand that you want to search\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%s", brand);
		int num_of_special_brand_cars = sum_special_brand_cars(brand);
		printf("there are %d cars in this brand\n\n----------------------------------------------------------------------------------------------------\n", num_of_special_brand_cars);
		int list = 1;
		for (int counter = 0; counter < system.num_of_cars; counter++)
		{
			if (strcmp(cars[counter].brand, brand) == 0)
			{
				printf("----------------------\n%d-", list);
				printf("name: %s\nmodel: %s\nyear of production: %d\ncolor: %s\nchassis number: %d\nfuel type: %s\nfunction: %s\nbuying price: %d\nselling price: %d\nbrand: %s\n\n", cars[counter].name, cars[counter].model, cars[counter].year_of_production, cars[counter].color, cars[counter].chassis_number, cars[counter].fuel_model, cars[counter].function, cars[counter].buying_price, cars[counter].selling_price, cars[counter].brand);
				printf("----------------------\n\n");
				list++;
			}
		}
	}
	return;
}
void show_cars_by_price()
{
	if (system.num_of_cars == 0)
	{
		printf("there is not any cars\n\n----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		int max_price, min_price;
		printf("enter max price\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &max_price);
		printf("enter min price\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &min_price);
		if (min_price > max_price)
		{
			printf("min price can not be more than max price\nplease enter valid numbers for next try\n\n----------------------------------------------------------------------------------------------------\n");
			return;
		}
		int sort_price = min_price;
		int list = 1;
		for (int sort_price = min_price; sort_price <= max_price; sort_price++)
		{
			for (int counter = 0; counter < system.num_of_cars; counter++)
			{
				if (cars[counter].buying_price == sort_price)
				{
					printf("----------------------\n%d-", list);
					printf("name: %s\nmodel: %s\nyear of production: %d\ncolor: %s\nchassis number: %d\nfuel type: %s\nfunction: %s\nbuying price: %d\nselling price: %d\nbrand: %s\n\n", cars[counter].name, cars[counter].model, cars[counter].year_of_production, cars[counter].color, cars[counter].chassis_number, cars[counter].fuel_model, cars[counter].function, cars[counter].buying_price, cars[counter].selling_price, cars[counter].brand);
					printf("----------------------\n\n");
					list++;
				}
			}
		}
		if (list == 1)
		{
			printf("There is not any cars in this range\n\n----------------------------------------------------------------------------------------------------\n");
		}
	}
	return;
}
void account()
{
	int enter = 0;
	while (enter != 5)
	{
		printf("enter a number to doing its action\n1-add car\n2-edit car\n3-report special brand cars\n4-show cars by price\n5-Exit\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &enter);
		if (enter == 1)
		{
			add_car();
			write_file();
		}
		else if (enter == 2)
		{
			edit_car();
			write_file();
		}
		else if (enter == 3)
		{
			report_special_brand_cars();
			write_file();
		}
		else if (enter == 4)
		{
			show_cars_by_price();
			write_file();
		}
	}
	write_file();
	printf("We Hope you enjoyed this program\nBy\n\n----------------------------------------------------------------------------------------------------\n");
	return;
}
void start()
{
	read_file();
	printf("Welcome to Car exhibition\n\n----------------------------------------------------------------------------------------------------\n");
	if (system.max_car == -1)
	{
		printf("Enter maximum of car that Car exhibition can hold\n\n----------------------------------------------------------------------------------------------------\n");
		scanf("%d", &system.max_car);
		write_file();
	}
	account();
	return;
}
//------------------------------------------------------------------main--------------------------------------------------------------------------------------------------
int main()
{
	start();
	return 0;
}
//------------------------------------------------------------------finish-----------------------------------------------------------------------------------------------