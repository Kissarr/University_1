﻿#pragma warning(disable: 4996)
# include <stdio.h>
# include <locale.h>																				//Для русского языка

int Score = 50;																						//Глобальное начальное количество очков

int Diapozon()																						//Функция по определению диапазона и защита от "дурака"
{
	int x, y;
	char buf[1024] = { '\0' };																		//Введем пустой массив 
	printf("Необходимо ввести диапазон загадываемых чисел:\nПервое число: "); scanf ("%s", buf);	//Сканирование 1 числа
	x = atoi(buf);																					//Взятие х из массива (конвертирание массива в инт)
	if (x < 0 || x > 0 || (buf[0] == '0' && buf[1] == '\0')) {										//Проверка на то что это число а не что-то другое
		buf[0] = '\0';																				//Обнуление массива
	}
	else {																							//Если это не число
		while (x==0 && buf[0] != '0'){																//Защита от дурака
			printf("Введены некорректные данные. Попробуйте снова\nПервое число: ");				//Защита от дурака
			buf[0] = '\0';																			//Защита от дурака
			scanf("%s", buf);																		//Защита от дурака
			x = atoi(buf);																			//Защита от дурака
		}																					
	}

	buf[0] = '\0';																					//Обнуление массива									
	printf("Второе число: "); scanf ("%s", buf);													//Сканирование 1 числа
	y = atoi(buf);
	if (y < 0 || y > 0 || (buf[0] == '0' && buf[1] == '\0')) {										//Если первое чило нормальное
		buf[0] = '\0';																				//Обнуление массива	
	}
	else {																							
		while (y == 0 && buf[0] != '0') {															//Защита от дурака
			printf("Введены некорректные данные. Попробуйте снова\nВторое число:");					//Защита от дурака
			buf[0] = '\0';																			//Защита от дурака
			scanf("%s", buf);																		//Защита от дурака
			y = atoi(buf);																			//Защита от дурака
		}
	}
	
	srand(time(NULL));
	if (x < y) {																					//Сравнение чисел если х больше у
		int number = (x + rand() % (y - x + 1));
		//printf("%d", number);
		return number;
	}
	if (x > y) {																					//Сравнение чисел если у больше х
		int number = (y + rand() % (x - y + 1));
		//printf("%d", number);
		return number;
	}
	if (x == y) {																					//Сравнение чисел если х равен у
		printf("Диапазон равен 0, Введите корректные данные\n");
		Diapozon();
	}

}																					
int CountTry() {																					//Функция по вводу количества попыток и защита от "дурака"
	int try_attemp;
	char buf2[1024] = { '\0' };																				
	printf("Необходимо ввести количество попыток отгадать число: "); scanf ("%s", buf2); printf("\n");		
	try_attemp = atoi(buf2);																				
	if (try_attemp >= 1) {
		return(try_attemp);
	}
	if (try_attemp < 1) {
		printf("Введите некорректное количество попыток (больше 1)\n");
		CountTry();
	}
	
}
int ScoreCount() {																					//Функция покупки очков
	int Score;
	char buf3[1024] = { '\0' };
	printf("Хотите купить фишки, по курсу 100$ к 65?\nИзначально у вас есть бонусные 50 фишек\nСколько вы готовы потратить?: "); scanf("%s", buf3);
	Score = atoi(buf3);
	if (Score > 0) {
		return(Score*0.65);
	}

	if (Score <= 0) {																				//Если это не число
		while (Score == 0 && buf3[0] != '0'|| Score < 0) {											//Защита от дурака
			printf("Введены некорректные количество. Попробуйте снова\n");							//Защита от дурака
			buf3[0] = '\0';																			//Защита от дурака
			scanf("%s", buf3);																		//Защита от дурака
			Score = atoi(buf3);																		//Защита от дурака
		}
		return(Score * 0.65);																		//Перевод женег в очки с отбрасыванием дробной части
		
	}
}
int Bid() {																							//Функция ставки и защита от дураков
	int bid;
	char buf4[1024] = { '\0' };																		
	printf("Ваше количество очков: %d\n", Score);
	printf("Необходимо выбрать размер ставки: "); scanf("%s", buf4);
	bid = atoi(buf4);
	if (bid == 0 && buf4[0] != '0') {																//Защита от дурака
		while (bid == 0 && buf4[1] != '0') {														//Защита от дурака
			printf("Введены некорректные данные. Попробуйте снова\n");								//Защита от дурака
			buf4[0] = '\0';																			//Защита от дурака
			scanf("%s", buf4);																		//Защита от дурака
			bid = atoi(buf4);																		//Защита от дурака
		}
		return(bid);
	}
	if (bid <= Score && bid > 0) {																	//Если все нормально 
		return(bid);
	}
	if (bid > Score || bid < 0) {																	//При попытке поставить больше чем есть или меньше 0
		printf("Вы не можете поставить больше чем у вас есть или меньше нуля\nВ данный моменту у вас %d\nПопробуйте снова\n",Score);
		Bid();
	}
}
int End() {																							//Функция конца игры, просто для того что бы не повторять ее 2 раза
	int ret;
	scanf_s("%d", &ret);
	switch (ret) {																					//Использование Switch
	case 1:
		main();																						//ЫЫЫ рекурсия(грузит память но все работает)
		break;
	default:
		printf("КОНЕЦ ИГРЫ\n");
		
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");																		//Русский язык
	printf("Выберите режим игры\nБыстрая игра-1\nПользовательская игра-2\n");
	int Rezim_igri;
	char z[1024] = { '\0' };
	scanf("%s", z);																					//Защита от дурака
	Rezim_igri = atoi(z);																			//Защита от дурака
	while (Rezim_igri != 1 && Rezim_igri != 2) {													//Защита от дурака	
		printf("Введены некорректные данные. Попробуйте снова\n");									//Защита от дурака
		z[0] = '\0';																				//Защита от дурака
		scanf("%s", z);																				//Защита от дурака
		Rezim_igri = atoi(z);
	}
	if (Rezim_igri == 1) {																			//Начало цикла с игрой в быстром режиме
		srand(time(NULL));
		int nmb = (rand() % (101));
		int tryc = 10;
		printf("Попробуйте угадать число от 0 до 100\n Оставшееся количество попыток % d\n ",tryc);
		while (tryc >0) {																			
			int try_numberez;
			char bb[1024] = { '\0' };																//Защита от дурака
			scanf("%s", bb);																		//Защита от дурака
			try_numberez = atoi(bb);																//Защита от дурака
			while (try_numberez == 0 && bb[1] != '0') {												//Защита от дурака
				printf("Введены некорректные данные. Попробуйте снова\n");							//Защита от дурака
				bb[0] = '\0';																		//Защита от дурака
				scanf("%s", bb);																	//Защита от дурака
				try_numberez = atoi(bb);															//Защита от дурака
			}
			if (try_numberez == nmb) {																//Сравнение числа из диапазона с введенным числом
				tryc = tryc - 1;																	//Уменьшение количества попыток
				printf("Поздравляем! Вы угадали число\n");
				printf("Попробовать снова? Для продолжения игры введите 1, для отмены игры введите любое другое число\n");				//Предложение продолжить игру
				End();
				return ("777");
			}
			if (try_numberez != nmb) {																//Сравнение числа из диапазона с введенным числом
				if (try_numberez > nmb) {															//Сравнение числа из диапазона с введенным числом если введенное число больше
					tryc = tryc - 1;																//Уменьшение количества попыток
					printf("Попробуйте снова, загаданное число меньше \nОставшееся количество попыток %d\n ", tryc);
				}
				if (try_numberez < nmb) {															//Сравнение числа из диапазона с введенным числом если введенное число меньше
					tryc = tryc - 1;																//Уменьшение количества попыток
					printf("Попробуйте снова, загаданное число больше \nОставшееся количество попыток %d\n ", tryc);
				}
			}
		}
		if (tryc <= 0) {																			//Действие если количество очков стало отрицательным или равным 0
			printf("\nВы проиграли\nПопробовать снова?\nДля продолжения игры введите 1, для отмены игры введите любое другое число\n");	//Предложение продолжить игру + информация о проигрыше
			End();
			return ("777");
		}

	}

	if (Rezim_igri == 2) {																			//Начало цикла с игрой в пользовательском режиме


		Score = Score + ScoreCount();
		int number = Diapozon();																	//Вызов функции с числом из заданного диапазона
		int try_attemp = CountTry();																//Вызов функции с числом попыток
		int bid = Bid();																			//Вызов функции с ставкой

		printf("Попробуйте угадать число\n  Количество очков %d\n  Оставшееся количество попыток % d\n ", Score, try_attemp);

		while (try_attemp > 0 && Score >= 0) {														//Начало цикла с игрой
			int try_number;																				
			char b[1024] = { '\0' };																//Защита от дурака
			scanf("%s", b);																			//Защита от дурака
			try_number = atoi(b);																	//Защита от дурака
			while (try_number == 0 && b[1] != '0') {												//Защита от дурака
				printf("Введены некорректные данные. Попробуйте снова\n");							//Защита от дурака
				b[0] = '\0';																		//Защита от дурака
				scanf("%s", b);																		//Защита от дурака
				try_number = atoi(b);																//Защита от дурака
			}

			if (try_number == number) {																//Сравнение числа из диапазона с введенным числом
				if (try_attemp < 5) {
					Score = Score + (2 * bid);														//Если количество попыток меньше 5
				}
				else if (try_attemp > 10) {
					Score = Score + (0.5 * bid);													//Если количество попыток больше 10
				}
				else {																				//Если количество попыток больше ль 5 до 10
					Score = Score + bid;
				}
				try_attemp = try_attemp - 1;														//Уменьшение количества попыток
				printf("Поздравляем! Вы угадали число\n  Количество очков %d\n  Оставшееся количество попыток %d\n ", Score, try_attemp);
				printf("Попробовать снова? Для продолжения игры введите 1, для отмены игры введите любое другое число\n");			//Предложение продолжить игру
				End();
				return ("777");
			}

			if (try_number != number) {																//Сравнение числа из диапазона с введенным числом
				if (try_number > number) {															//Сравнение числа из диапазона с введенным числом если введенное число больше
					try_attemp = try_attemp - 1;													//Уменьшение количества попыток
					printf("Попробуйте снова, загаданное число меньше \n  Количество очков %d\n  Оставшееся количество попыток %d\n ", Score, try_attemp);
				}
				if (try_number < number) {															//Сравнение числа из диапазона с введенным числом если введенное число меньше
					try_attemp = try_attemp - 1;													//Уменьшение количества попыток
					printf("Попробуйте снова, загаданное число больше \n  Количество очков %d\n  Оставшееся количество попыток %d\n ", Score, try_attemp);
				}
			}

		}
		if (try_attemp <= 0 || Score < 0) {															//Действие если количество очков стало отрицательным или равным 0
			printf("\nВы проиграли и потеряли вашу ставку\nПопробовать снова?\nДля продолжения игры введите 1, для отмены игры введите любое другое число\nЕсли денег не осталось можете продолжать играть без ставок или обменять деньги на фишки\n");	//Предложение продолжить игру + информация о проигрыше
			Score = Score - bid;																	//Уменьшение количества очков
			printf("Количество очков %d\n", Score);
			End();
			return ("777");
		}
	}

}

