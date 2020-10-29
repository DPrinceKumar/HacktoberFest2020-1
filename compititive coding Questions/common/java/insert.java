static void insert (int i)
{
    if (isfully())
    {
        System.out.println("maaf, antrian penuh");
    }else {
        System.out.println("nilai " + i + "masuk antrian");
        queue[top++] = i;
    }
}
