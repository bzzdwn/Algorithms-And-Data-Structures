using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Numerics;
using System.Threading;


public class Runnable
{
    public static void Run()
    {
        System.IO.StreamReader input = new System.IO.StreamReader("in.txt");
        System.IO.StreamWriter output = new System.IO.StreamWriter("out.txt") { AutoFlush = true };

        long line_length = Convert.ToInt64(input.ReadLine()),
            querries = Convert.ToInt64(input.ReadLine()),
            occupied_length = 0;
        string tmp = input.ReadLine();
        if (querries == 0)
            output.Write(1);
        else
        {
            for (int i = 0; i < querries; i++)
            {
                long square_number;
                square_number = Convert.ToInt64(input.ReadLine());
                line_length -= square_number;
            }
            line_length++;
            if (occupied_length >= line_length || querries > line_length)
                output.Write(0);
            else
            {
                long size = line_length + 1;
                BigInteger[,] table = new BigInteger[size, size];
                for (int i = 0; i < size; i++)
                {
                    table[i, 0] = BigInteger.One;
                    table[i, i] = BigInteger.One;
                    for (int j = 1; j < i; j++)
                    {
                        table[i, j] = (table[i - 1, j - 1] + table[i - 1, j]);
                    }
                }
                output.Write(table[line_length, querries]);
            }
        }
        input.Close();
        output.Close();
    }
    public delegate void ThreadStart();
    static void Main(string[] args)
    {
        Int32 StackSize = 64 * 1024 * 1024;
        Thread thread = new Thread(Run, StackSize);
        thread.Start();
    }
}