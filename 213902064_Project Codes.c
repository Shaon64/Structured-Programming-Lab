/*
	Name: Md. Shaon Howlader
	ID: 213902064
	Email: shahriarhossenshaon4@gmail.com
	Project title: Phonebook System
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct contact_info{
	char name[20];
	char location[20];
	char email[20];
	char phone[20];
} contact_info;

typedef struct phonebook{
	contact_info * single_contact_info;
	struct phonebook * next_contact_info;
} phonebook;


phonebook * sample_data(phonebook * all_contact_info);
void dashboard();

contact_info * blank_contact_info();
phonebook * blank_phonebook();

void screen_phonebook(phonebook * all_contact_info);

contact_info * insert_contact_info(char * name, char * location, char * email, char * phone);
phonebook * insert_phonebook(phonebook * all_contact_info, contact_info * new_contact_info);

void search_phonebook_by_name(phonebook * all_contact_info, char * name);
void search_phonebook_by_location(phonebook * all_contact_info, char * location);
void search_phonebook_by_email(phonebook * all_contact_info, char * email);

phonebook * delete_phonebook_by_name(phonebook * all_contact_info, char * name);
phonebook * delete_phonebook_by_location(phonebook * all_contact_info, char * location);
phonebook * delete_phonebook_by_email(phonebook * all_contact_info, char * email);

phonebook * add_new_contact(phonebook * all_contact_info);
void search_contact(phonebook * all_contact_info);
phonebook * delete_contact(phonebook * all_contact_info);


int main(){

	phonebook * all_contact_info = NULL;
	dashboard(all_contact_info);

	return 0;
}

void dashboard(phonebook * all_contact_info){

	printf(
		"-------------\n"
		" dashboard\n"
		"-------------\n"
		"\n"
	);

	printf(
		"1. add new contact\n"
		"2. show all contact\n"
		"3. search contact\n"
		"4. delete a contact info\n"
		"5. inser sample data\n"
		"6. exit\n"
		"\n"
	);

	printf(
		"type option: "
	);

	int option;
	scanf("%d", &option);

	system("cls");

	if(option == 1){
		all_contact_info = add_new_contact(all_contact_info);
	}else if(option == 2){
		screen_phonebook(all_contact_info);
	}else if(option == 3){
		search_contact(all_contact_info);
	}else if(option == 4){
		all_contact_info = delete_contact(all_contact_info);
	}else if(option == 5){
		all_contact_info = sample_data(all_contact_info);
	}else if(option == 6){
		printf(
			"\n"
			"the application has been terminated.\n"
		);
		exit(0);
	}

	printf(
		"\n"
		"click to continue...\n"
	);
	getch();
	system("cls");

	dashboard(all_contact_info);
}

phonebook * delete_contact(phonebook * all_contact_info){
	printf(
		"-------------\n"
		" delete contact\n"
		"-------------\n"
		"\n"
	);

	printf(
		"1. delete by name\n"
		"2. delete by email\n"
		"\n"
	);

	printf(
		"type option: "
	);

	int option;
	scanf("%d", &option);

		if(option == 1){
		char name[20];
		getchar();
		printf("type your name: ");
		gets(name);
		all_contact_info = delete_phonebook_by_name(all_contact_info, name);
	}else if(option == 2){
		char email[20];
		getchar();
		printf("type your email: ");
		gets(email);
	 	all_contact_info = delete_phonebook_by_email(all_contact_info, email);
	}
	return all_contact_info;
}

void search_contact(phonebook * all_contact_info){
	printf(
		"-------------\n"
		" search contact\n"
		"-------------\n"
		"\n"
	);

	printf(
		"1. search by name\n"
		"2. search by email\n"
		"\n"
	);

	printf(
		"type option: "
	);

	int option;
	scanf("%d", &option);

		if(option == 1){
		char name[20];
		getchar();
		printf("type your name: ");
		gets(name);
		search_phonebook_by_name(all_contact_info, name);
	}else if(option == 2){
		char email[20];
		getchar();
		printf("type your email: ");
		gets(email);
		search_phonebook_by_email(all_contact_info, email);
	}
}

phonebook * add_new_contact(phonebook * all_contact_info){

	printf(
		"-------------\n"
		" add new contact\n"
		"-------------\n"
		"\n"
	);

	char name[20];
	char location[20];
	char email[20];
	char phone[20];

	printf(
		"name: "
	);
	getchar();
	gets(name);


	printf(
		"location: "
	);
	gets(location);

	printf(
		"email: "
	);
	gets(email);

	printf(
		"phone number: "
	);
	gets(phone);

	contact_info * new_contact_info = insert_contact_info(name, location, email, phone);
	all_contact_info = insert_phonebook(all_contact_info, new_contact_info);
	return all_contact_info;
}

phonebook * delete_phonebook_by_location(phonebook * all_contact_info, char * location){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	phonebook * blank = blank_phonebook();
	phonebook * temp1 = blank_phonebook();
	if(strcmp(each_contact_info -> single_contact_info -> location, location) == 0){
		blank = each_contact_info -> next_contact_info;
		free(each_contact_info);
		all_contact_info = blank;
	}else{
		while(each_contact_info -> next_contact_info != NULL){
			if(strcmp(each_contact_info -> next_contact_info -> single_contact_info -> location, location) == 0){
				each_contact_info -> next_contact_info = each_contact_info -> next_contact_info -> next_contact_info;
				break;
			}
			each_contact_info = each_contact_info -> next_contact_info;
		}
	}
	return all_contact_info;
}

phonebook * delete_phonebook_by_name(phonebook * all_contact_info, char * name){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	phonebook * blank = blank_phonebook();
	phonebook * temp1 = blank_phonebook();
	if(strcmp(each_contact_info -> single_contact_info -> name, name) == 0){
		blank = each_contact_info -> next_contact_info;
		free(each_contact_info);
		all_contact_info = blank;
	}else{
		while(each_contact_info -> next_contact_info != NULL){
			if(strcmp(each_contact_info -> next_contact_info -> single_contact_info -> name, name) == 0){
				each_contact_info -> next_contact_info = each_contact_info -> next_contact_info -> next_contact_info;
				break;
			}
			each_contact_info = each_contact_info -> next_contact_info;
		}
	}
	return all_contact_info;
}

phonebook * delete_phonebook_by_email(phonebook * all_contact_info, char * email){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	phonebook * blank = blank_phonebook();
	phonebook * temp1 = blank_phonebook();
	if(strcmp(each_contact_info -> single_contact_info -> email, email) == 0){
		blank = each_contact_info -> next_contact_info;
		free(each_contact_info);
		all_contact_info = blank;
	}else{
		while(each_contact_info -> next_contact_info != NULL){
			if(strcmp(each_contact_info -> next_contact_info -> single_contact_info -> email, email) == 0){
				each_contact_info -> next_contact_info = each_contact_info -> next_contact_info -> next_contact_info;
				break;
			}
			each_contact_info = each_contact_info -> next_contact_info;
		}
	}
	return all_contact_info;
}

void search_phonebook_by_email(phonebook * all_contact_info, char * email){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	printf(
		"------------------------------------------------------------------------------\n"
		"name\t\tlocation\t\temail\t\t\tphone\n"
		"------------------------------------------------------------------------------\n"
		"\n"
	);

	while(each_contact_info != NULL){
		if(strcmp(each_contact_info -> single_contact_info -> email, email) == 0){
			printf(
				"%.6s\t\t"
				"%.8s\t\t\t"
				"%.14s\t\t"
				"%.12s\n",
				each_contact_info -> single_contact_info -> name,
				each_contact_info -> single_contact_info -> location,
				each_contact_info -> single_contact_info -> email,
				each_contact_info -> single_contact_info -> phone
			);
		}
		each_contact_info = each_contact_info -> next_contact_info;
	}
}

void search_phonebook_by_location(phonebook * all_contact_info, char * location){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	printf(
		"------------------------------------------------------------------------------\n"
		"name\t\tlocation\t\temail\t\t\tphone\n"
		"------------------------------------------------------------------------------\n"
		"\n"
	);

	while(each_contact_info != NULL){
		if(strcmp(each_contact_info -> single_contact_info -> location, location) == 0){
			printf(
				"%.6s\t\t"
				"%.8s\t\t\t"
				"%.14s\t\t"
				"%.12s\n",
				each_contact_info -> single_contact_info -> name,
				each_contact_info -> single_contact_info -> location,
				each_contact_info -> single_contact_info -> email,
				each_contact_info -> single_contact_info -> phone
			);
		}
		each_contact_info = each_contact_info -> next_contact_info;
	}
}

void search_phonebook_by_name(phonebook * all_contact_info, char * name){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	printf(
		"------------------------------------------------------------------------------\n"
		"name\t\tlocation\t\temail\t\t\tphone\n"
		"------------------------------------------------------------------------------\n"
		"\n"
	);

	while(each_contact_info != NULL){
		if(strcmp(each_contact_info -> single_contact_info -> name, name) == 0){
			printf(
				"%.6s\t\t"
				"%.8s\t\t\t"
				"%.14s\t\t"
				"%.12s\n",
				each_contact_info -> single_contact_info -> name,
				each_contact_info -> single_contact_info -> location,
				each_contact_info -> single_contact_info -> email,
				each_contact_info -> single_contact_info -> phone
			);
		}
		each_contact_info = each_contact_info -> next_contact_info;
	}
}

void screen_phonebook(phonebook * all_contact_info){
	phonebook * each_contact_info = blank_phonebook();
	each_contact_info = all_contact_info;

	printf(
		"------------------------------------------------------------------------------\n"
		"name\t\tlocation\t\temail\t\t\tphone\n"
		"------------------------------------------------------------------------------\n"
		"\n"
	);

	while(each_contact_info != NULL){
		printf(
			"%.6s\t\t"
			"%.8s\t\t\t"
			"%.14s\t\t"
			"%.12s\n",
			each_contact_info -> single_contact_info -> name,
			each_contact_info -> single_contact_info -> location,
			each_contact_info -> single_contact_info -> email,
			each_contact_info -> single_contact_info -> phone
		);
		each_contact_info = each_contact_info -> next_contact_info;
	}
}

phonebook * insert_phonebook(phonebook * all_contact_info, contact_info * new_contact_info){
	phonebook * new_contact = blank_phonebook();
	new_contact -> single_contact_info = new_contact_info;

	phonebook * temp = blank_phonebook();
	temp = all_contact_info;

	if(temp == NULL){
		all_contact_info = new_contact;
	}else{
		while(temp -> next_contact_info != NULL){
			temp  = temp -> next_contact_info;
		} 	
		temp -> next_contact_info = new_contact;
	}
	

	return all_contact_info;
}

contact_info * insert_contact_info(char * name, char * location, char * email, char * phone){
	contact_info * single_contact = blank_contact_info();
	strcpy(single_contact -> name, name);
	strcpy(single_contact -> location, location);
	strcpy(single_contact -> email, email);
	strcpy(single_contact -> phone, phone);

	return single_contact;
}

contact_info * blank_contact_info(){
	contact_info * blank = (contact_info *) malloc(sizeof(contact_info));
	return blank;
}

phonebook * blank_phonebook(){
	phonebook * blank = (phonebook *) malloc(sizeof(phonebook));
	blank -> next_contact_info = NULL;
	return blank;
}

phonebook * sample_data(phonebook * all_contact_info){
	 
	contact_info * new_contact_info1 = insert_contact_info("name1", "locati1", "mail1@mail.com", "123123123");
	contact_info * new_contact_info2 = insert_contact_info("name2", "locati2", "mail2@mail.com", "123123123");
	contact_info * new_contact_info3 = insert_contact_info("name3", "locati3", "mail3@mail.com", "123123123");
	contact_info * new_contact_info4 = insert_contact_info("name4", "locati4", "mail4@mail.com", "123123123");

	all_contact_info = insert_phonebook(all_contact_info, new_contact_info1);
	all_contact_info = insert_phonebook(all_contact_info, new_contact_info2);
	all_contact_info = insert_phonebook(all_contact_info, new_contact_info3);
	all_contact_info = insert_phonebook(all_contact_info, new_contact_info4);

	return all_contact_info;
}
