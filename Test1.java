public class Test1 { 

    static 
     {
        try
        {
            System.load("F:\\CSharpHelloWorld.dll");
        }
        catch (Exception je)
        {
            System.out.println(je);
        }
    }
    static CSharpHelloWorld dbobj = new CSharpHelloWorld();

    public native void displayHelloWorld();

    public static void main (String[] args) 
    {
        try
        {
            Test1 t = new Test1();
            t.displayHelloWorld();
        }
        catch (Exception je)
        {
            System.out.println(je);
        }
        // Test1 t = new Test1();
        CSharpHelloWorld.displayHelloWorld();
    }
}