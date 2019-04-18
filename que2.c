#include<stdio.h>j
	void check_at();

	int main()
{

	int n, time=0,i=0,j,k=0,total_bt=0,temp1,temp2,temp3,tt;
	int q1=3,q2=6;
	int front=0,f=0;
	int rear=0,r=0;
	int at[i],bt[i],rbt[i],wt[i],ctime[i],tat[i];
	int flag[i];
	flag[0]=0;
	int temp_rbt[k],t[i];
	int queue_1[total_bt];		// first queue
	int queue_2[total_bt];
	int q_3[total_bt];
	printf("\nEnter the no of process: ");
	scanf("%d",&n);					//total no of process
	for(i=0;i<=n-1;i++){				//entering at and bt
	printf("\nEnter Arrival Time and Burst Time for process P[%d]: ",i);//entering by user
		scanf("%d%d", &at[i],&bt[i]);
		rbt[i]=bt[i];
		total_bt=total_bt+bt[i];
		}






	printf("\n\tProcess\t|\tArival Time\t|\tBurst Time\t|");
	//sorting process in accending ordre wrt at
	for (i=0 ; i<=n-1;i++){
		for (j=0 ; j<n-i-1 ; j++){
			if(at[j]>at[j+1] ){
	printf("1\n");
				temp1=at[j];
				temp2=rbt[j];
				temp3=bt[j];
				at[j]=at[j+1];
				rbt[j]=rbt[j+1];
				bt[j]=bt[j+1];
				at[j+1]=temp1;
				rbt[j+1]=temp2;
				bt[j+1]=temp3;
				}
			}
	}
	//adding first process to queue1
	if(rear==total_bt){
		printf("\nOverflow");
		}
	else{
		printf("\nfirst process entered.");
		rear=rear+1;
		queue_1[rear]=rbt[0];
		printf("]\nqueue_1=%d added",queue_1[rear]);
	printf("\n2");
		}
	//process scheduling initiated
	i=0;
	printf("\n1flag[%d]: %d",i,flag[i]);
	do{
	if(front>=rear){
		printf("\nfront :%d\nrear :%d",front,rear);
		printf("\nunderflow");

		}
	else{
		rbt[i]=queue_1[front];
		front=front+1;
		if(flag[i]==0){

			//if process traversed first time
			if(rbt[i]>q1){
				printf("\n1flag[%d]: %d",i,flag[i]);
				time=time+q1;
				rbt[i]=rbt[i]-q1;
				flag[i]++;

				for(j=front+1;j<n;j++){
					if(at[j]<=time){
					rear=rear+1;
					queue_1[rear]=rbt[j];

					}
				}

				rear=rear+1;
				queue_1[rear]=rbt[i];

			}
			//if process traversed second time
			else{
				printf("\n1flag[%d]: %d",i,flag[i]);
				time=time+rbt[i];

				for(j=front+1;j<n;j++){
					if(at[j]<=time){
					rear=rear+1;
					queue_1[rear]=rbt[j];
					printf("10\n");
					}
				}

				flag[i]++;
				ctime[i]=time;
				tat[i]=ctime[i]-at[i];
				wt[i]=tat[i]-bt[i];
			}


		//	printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ctime[i],tat[i],wt[i]);


		}


		else if(flag[i]==1){
			//if process traversed first time

			if(rbt[i]>q2){
				printf("\n1flag[%d]: %d",i,flag[i]);
				time=time+q2;
				rbt[i]=rbt[i]-q2;

				for(j=front+1;j<n;j++){
					if(at[j]<=time){
					rear=rear+1;
					queue_1[rear]=rbt[j];
					printf("10\n");
					}
				}

				flag[i]++;
				rear=rear+1;
				queue_1[rear]=rbt[i];



			}
			//if process traversed second time
			else{
				printf("\n1flag[%d]: %d",i,flag[i]);
				time=time+rbt[i];
				flag[i]++;

				for(j=front+1;j<n;j++){
					if(at[j]<=time){
					rear=rear+1;
					queue_1[rear]=rbt[j];
					printf("10\n");
					}
				}

				ctime[i]=time;
				tat[i]=ctime[i]-at[i];
				wt[i]=tat[i]-bt[i];
			//	printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ctime[i],tat[i],wt[i]);


