import java.util.*;
class dfa1
{
    public static void main(String [] args)
    {
        System.out.println("enter total number of states");
        Scanner sc= new Scanner(System.in);
        int no= sc.nextInt();
        String [] stt = new String[no];
        
        System.out.println("enter the states");
        for(int i=0; i<no ; i++)
        {
            stt[i]=sc.next();
            
        }
        
        System.out.println("enter the initial state");
        String ini= sc.next();
        
        System.out.println("enter number of final states");
        int fi= sc.nextInt();
        
        System.out.println("enter the final states");
        String [] stf= new String[fi];
	
        for(int i=0; i<fi ; i++)
        {
            stf[i]=sc.next();
            
        }
        
        System.out.println("enter the number of input alpahbets");
        int in= sc.nextInt();
        
        System.out.println("enter the input alphabets");
        String [] alp= new String[in];
	for(int i=0; i<in ; i++)
        {
            alp[i]=sc.next();
            
        }
        
        String [][] tf= new String[no][in];

	System.out.println("new states");
        
        for(int i=0; i<no; i++)
        {
            for(int j=0; j<in; j++)
            {
                tf[i][j]=sc.next();
            }
        }
        
        for(int i=0; i<no; i++)
        {
            for(int j=0; j<in; j++)
            {
                System.out.print(tf[i][j]);
            }
		System.out.println();
        }
        
            
        
    }
}
