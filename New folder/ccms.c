#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const char admin_username[]="admin";
const char admin_pass[]="admin39";

int no_of_mem=0;
int search(char*);
void remove_newline(char*);
void flush();

struct members{
	char id_no[8];
	char pass[20];
}m[5000];

void remove_newline(char s[200]){
	s[strlen(s)-1]='\0';
}

void flush(){
	while(getchar()!='\n');
}

int search(char id[8]){
	int i=0;
	while(i<=no_of_mem){
		if(strcmp(m[i].id_no,id)==0)
			return 1;
		i++;
	}
	return 0;
}

int main()
{
	FILE *details, *pass,*fp;
	int p=0,j,i,found=0,n=1,g=1;
	char log_pass[20],file_name[30],file_name1[30],file_name3[30],read[200],ch,name[30],ph_no[30],address[100],id[8],voter_id[30],aadhar_no[30],password[30],con_pass[30],pass1[30],user[30],get_id[20];
	details = fopen("cyber.txt", "a+");
	if (details== NULL)
	{
		printf("\n cannot open file...");
		exit(1);
	}
	while(fgets(m[no_of_mem].id_no,sizeof(m[no_of_mem].id_no),details)){
		remove_newline(m[no_of_mem].id_no);
		fgets(m[no_of_mem].pass,sizeof(m[no_of_mem].pass),details);
		remove_newline(m[no_of_mem].pass);
		no_of_mem++;
	}
	fclose(details);
	printf("\n1. Admin");
	printf("\n2. Members");
	printf("\n3. Exit\n");
	printf("\nEnter your choice: ");
	scanf("%d",&i);
	switch (i)
	{
		case 1:
			flush();
			printf("\n********Admin's Area********\n");
			printf("\nEnter username: ");
			fgets(user,sizeof(user),stdin);
			remove_newline(user);
			if(strcmp(user,admin_username)==0){
				printf("\nEnter password: ");
				fgets(pass1,sizeof(pass1),stdin);
				remove_newline(pass1);
					if(strcmp(pass1,admin_pass)==0){
						do{
							printf("\n1. View member's details");
							printf("\n2. New membership");
							printf("\n3. Back\n");
							printf("\nEnter your choice: ");
							scanf("%d", &j);
							switch (j)
							{
								case 1:
									do{
										printf("\nEnter id to view: ");
										scanf("%s",get_id);
										if(search(get_id)){
											strcpy(file_name,get_id);
											strcat(file_name,".txt");
		  									fp=fopen(file_name,"a+");
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nName: %s",read);
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nPhone: %s",read);
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nAddress: %s",read);
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nID: %s",read);
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nVoter ID: %s",read);
		  									fgets(read,sizeof(read),fp);
		  									remove_newline(read);
		  									printf("\nAadhar No: %s",read);
		  									fclose(fp);
		  								}
		  								else
		  									printf("\nNo member found with that id!");
		  								printf("\nDo you want to view more details?Enter Y to do so: ");
		  								flush();
		  								ch=getchar();
		  							}while(toupper(ch)=='Y');
		  						break;
								case 2:
									printf("\nEnter member's details...\n");
									do
									{
										printf("\nEnter name: ");
										scanf("%s",name);
										printf("\nEnter phone no: ");
										scanf("%s",ph_no);
										printf("\nEnter address: ");
										scanf("%s",address);
										printf("\nEnter id: ");
										scanf("%s",id);
										printf("\nEnter voter id no: ");
										scanf("%s",voter_id);
										printf("\nEnter aadhar no: ");
										scanf("%s",aadhar_no);
										printf("\nEnter password: ");
										scanf("%s",password);
										do
           					 			{
           					 				printf("\nConfirm password: ");
											scanf("%s",con_pass);
											if(strcmp(password,con_pass)==0)
              	 							break;
            								else
											printf("\nPassword doesn't match!");
            							}while(1);
            							strcpy(file_name1,id);
            							strcat(file_name1,".txt");
            							details=fopen(file_name1,"a+");
										fputs(name,details);
										fputs("\n",details);
										fputs(ph_no,details);
										fputs("\n",details);
										fputs(address,details);
										fputs("\n",details);
										fputs(id,details);
										fputs("\n",details);
										fputs(voter_id,details);
										fputs("\n",details);
										fputs(aadhar_no,details);
										fputs("\n",details);
           	 							fclose(details);
										pass=fopen("cyber.txt","a+");
           								fputs(id,pass);
           								fputs("\n",pass);
          	 							fputs(password,pass);
          	 							fputs("\n",pass);
										strcpy(m[no_of_mem].id_no,id);
										strcpy(m[no_of_mem].pass,password);
										no_of_mem++;
										printf("\nCongratulations !!! new membership has been taken succesfully...");
										fclose(pass);
										printf("\nDo you want to create more id(Y/N): ");
										flush();
										ch=getchar();
									}while(toupper(ch)=='Y');
								break;
								case 3:
									n=0;
								break;
								}
							}while(n);

						}
						else{
							printf("\nWrong Pass");
							exit(0);
						}
					}
					else{
						printf("Wrong Username");
						exit(0);
					}

		break;
		case 2:
			flush();
			printf("\n********Member's Area********\n");
			printf("\nEnter id: ");
			fgets(user,sizeof(user),stdin);
			remove_newline(user);
			while(p<=no_of_mem){
				if(strcmp(m[p].id_no,user)==0){
					found=1;
					break;
				}
				p++;
			}
			if(found){
				printf("\nEnter password: ");
				fgets(pass1,sizeof(pass1),stdin);
				remove_newline(pass1);
				if(strcmp(pass1,m[p].pass)==0){
					printf("\nYou are logged in successfully!");
					printf("\nLog in time: %s\n",__TIME__);
					do{
						printf("\n*****Menu*****\n");
						printf("\n1. View own details");
	      				printf("\n2. Log out");
	      				printf("\nEnter your choice: ");
	      				scanf("%d",&i);
	      				strcpy(file_name3,user);
	      				strcat(file_name3,".txt");
	      				fp=fopen(file_name3,"r");
	      				if(fp==NULL){
	      					printf("\nFile can't be opened");
	      					exit(1);
	      				}
	      				switch(i){
	      					case 1:
	      					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nName: %s",read);
		  					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nPhone: %s",read);
		  					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nAddress: %s",read);
		  					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nID: %s",read);
		  					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nVoter ID: %s",read);
		  					fgets(read,sizeof(read),fp);
		  					remove_newline(read);
		  					printf("\nAadhar No: %s",read);
		  					fclose(fp);
	      					break;
	    					case 2:
	    						printf("\nYou are logged out successfully!");
	    						printf("\nLog out time: %s\n",__TIME__);
	    						g=0;
	    					break;
	      				}
	      			}while(g);
				}
				else{
					printf("\nWrong Password!");
					exit(0);
				}
			}
			else{
				printf("Wrong Username");
				exit(0);
			}
		break;
		case 3:
			exit(0);
	}
	return 0;
}
