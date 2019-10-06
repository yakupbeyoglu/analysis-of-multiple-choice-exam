#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void read_booklet(char[], char[], char[]);
void read_answers(char[][10], char[], char[][50]);
void read_info(char[][10], char[][30], char[][30], char[][10]);
//cevaplarisay yaz(dosyaadi,an_answers,book_a)




//void check_write(char[], char[], char[], char[], char[][50],char[][10],char [][30],char[][30],char[][10],int,int);//booka,bookb,bookc,type,answers
int main()
{


	char book_a[50], book_b[50], book_c[50];// Answer booklet a, answer booklet b ,answer booklet c 50 karakterlik cekecekler!
	char an_no[20][10], an_type[20], an_answers[20][50];//std answers 
	char no[20][10], name[20][30], surname[20][30], depart[20][10];//information kismi
	int size_person = 20, size_answer = 50;//kac kisi oldugu ve kac adet cevap oldugu
	int empty = 0, wrong = 0, correct = 0;
	int i, j;
	int aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, count;
	int success_a = 0;
	float avarage;
	float score = 0;
	read_booklet(book_a, book_b, book_c);
	read_answers(an_no, an_type, an_answers); 
		read_info(no, name, surname, depart);
	FILE *write;
	write = fopen("yaz.txt", "w");//buraya kendi dosya yerini gosterecen 
	fprintf(write, "PART A  (RESULTS)\n\nStd.No\t\tName&Surname\t\t\tDepartment\t\tCorrect\t\twrong\t\tscore\n");//no=2,name=3mdepart=2,correcorrect2,wrong=2,score=2
	for (i = 0; i < size_person; i++)
	{


		if (an_type[i] == 'A')//a icin
		{
			correct = 0;
			wrong = 0;
			empty = 0;
			for (j = 0; j < size_answer; j++)
			{
				if (an_answers[i][j] == book_a[j])
				{
					correct++;

				}
				else
				{
					if (an_answers[i][j] == '*')
					{
						empty++;

					}
					else
					{
						wrong++;
					}
				}




			}

		}
		else if (an_type[i] == 'B')
		{
			correct = 0;
			wrong = 0;
			empty = 0;
			for (j = 0; j < size_answer; j++)
			{

				if (an_answers[i][j] == book_b[j])
				{
					correct++;

				}
				else
				{
					if (an_answers[i][j] == '*')
					{
						empty++;

					}
					else
					{
						wrong++;
					}
				}

			}
		}
		else if (an_type[i] == 'C')
		{
			correct = 0;
			wrong = 0;
			empty = 0;
			for (j = 0; j < size_answer; j++)
			{

				if (an_answers[i][j] == book_c[j])
				{
					correct++;

				}
				else
				{
					if (an_answers[i][j] == '*')
					{
						empty++;

					}
					else
					{
						wrong++;
					}
				}

			}

		}

		score = (correct - ((float)wrong / 4)) * 2;
		if (score < 0)
			score = 0;

		fprintf(write, "%s\t\t%s %s\t\t\t%s\t\t%d\t\t%d\t\t%.2f\n", an_no[i], name[i], surname[i], depart[i], correct, wrong, score);//no=2,name=3mdepart=2,correcorrect2,wrong=2,score=2

	}

	fprintf(write, "\n\n\nPART B (STATISTICS)\n\n");
	fprintf(write, "BOOKLET A :\n\n");   //printf("booklet a\n");//burayi sil
	fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
	for (j = 0; j < size_answer; j++)
	{
		avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;




		for (i = 0; i < size_person; i++)
		{
			if (an_type[i] == 'A')
			{
				count++;

				if (an_answers[i][j] == book_a[j])
					success_a++;
				if (an_answers[i][j] == 'A')
					aa++;
				else if (an_answers[i][j] == 'B')
					ab++;
				else if (an_answers[i][j] == 'C')
					ac++;
				else if (an_answers[i][j] == 'D')
					ad++;
				else
					ablank++;

			}
			avarage = ((float)success_a / count) * 100;
		}

		fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%%%.2f\n", j + 1, book_a[j], aa, ab, ac, ad, ablank, avarage);
		//printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t %% %.2f \n", j+1,success_a, aa, ab, ac, ad, ablank,avarage);
			//fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");


	}
	//printf("\n\nBooklet b\n");
	fprintf(write, "BOOKLET B :\n\n");
	fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
	for (j = 0; j < size_answer; j++)
	{
		avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;

		for (i = 0; i < size_person; i++)
		{
			if (an_type[i] == 'B')
			{//cevaplarisay yaz(dosyaadi,an_answers,book_a)
				count++;
				if (an_answers[i][j] == book_b[j])
					success_a++;
				if (an_answers[i][j] == 'A')
					aa++;
				else if (an_answers[i][j] == 'B')
					ab++;
				else if (an_answers[i][j] == 'C')
					ac++;
				else if (an_answers[i][j] == 'D')
					ad++;
				else
					ablank++;

			}
			avarage = ((float)success_a / count) * 100;

		}
		//printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t %% %.2f \n", j + 1, success_a, aa, ab, ac, ad, ablank, avarage);
		fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%%%.2f\n", j + 1, book_b[j], aa, ab, ac, ad, ablank, avarage);
	}
	//printf("\n\nBooklet c\n");
	fprintf(write, "BOOKLET C :\n\n");
	fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
	for (j = 0; j < size_answer; j++)
	{
		avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;

		for (i = 0; i < size_person; i++)
		{
			if (an_type[i] == 'C')
			{//cevaplarisay yaz(dosyaadi,an_answers,book_a)
				count++;
				if (an_answers[i][j] == book_c[j])
					success_a++;
				if (an_answers[i][j] == 'A')
					aa++;
				else if (an_answers[i][j] == 'B')
					ab++;
				else if (an_answers[i][j] == 'C')
					ac++;
				else if (an_answers[i][j] == 'D')
					ad++;
				else
					ablank++;

			}
			avarage = ((float)success_a / count) * 100;

		}

		//printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t %% %.2f \n", j + 1, success_a, aa, ab, ac, ad, ablank, avarage);
		fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%%%.2f\n", j + 1, book_c[j], aa, ab, ac, ad, ablank, avarage);


	}


	fclose(write);
	return 0;
}
void read_booklet(char a[], char b[], char c[])
{
	FILE * booklet; //booklet cevap anahtari kismi acildi! 
	booklet = fopen("booklet.txt", "r");//kendi dosya adini yazacan !!!!!
	int i = 0;//count sistmei icin kullanildi!

	if (booklet != NULL)
	{
		while (!feof(booklet))//feof yapilarak dosya sonuna kadar okunmasini sagladik!
		{
			if (i == 0)
			{
				fscanf(booklet, "%s", a);
				i++;//burada i nin degerini artirdik ki herseferinde artip b yi ve c yi okuyabilsin!
			}
			else if (i == 1)
			{

				fscanf(booklet, "%s", b);
				i++;

			}
			else
			{
				fscanf(booklet, "%s", c);
			}


		}
	}
	else
	{
		printf("we cant find this file!");
	}


	fclose(booklet);



	return;
}
void read_answers(char no[][10], char type[], char answer[][50])//cevaplari okumak icin acildi
{
	int i = 0;
	FILE *answers;
	answers = fopen("answers.txt", "r");//dosya konumu kendi dosya adini yazacan !!!!!
	if (answers != NULL)
	{
		while (!feof(answers))
		{

			fscanf(answers, "%s %s %s", &no[i], &type[i], &answer[i]);
			i++;



		}



	}
	else
	{
		printf("not found");
	}
	fclose(answers);



	return;
}
void read_info(char in_no[][10], char in_name[][30], char in_surname[][30], char in_depart[][10])//information kismini almak icin
{
	int i = 0;
	FILE *info;
	info = fopen("students.txt", "r");//kendi dosya adini yazacan !!!!!
	if (info != NULL)
	{
		while (!feof(info))
		{

			fscanf(info, "%s %s %s %s", &in_no[i], &in_name[i], &in_surname[i], &in_depart[i]);
			i++;


		}




	}
	else
	{
		printf("not foud");
	}




	fclose(info);
	return;

}


