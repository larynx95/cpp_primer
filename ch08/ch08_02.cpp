/******************************************************************************v
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Section 8.1 The IO Classes
Section 8.2 File Input and Output
******************************************************************************/

/*
  fstream fstrm          create an unbound file stream.
                         fstream is one of the types defined
                         in the fstream header
  fstream fstrm(s)       creates an fstream and opens the file named s.
                         s can have type string or can be a pointer to
                         a C-style character string
  fstream fstrm(s,mode)  like the previous constructor
                         but opens s in the given mode
  fstrm.open(s)          opens the file name by the s and
                         binds that file to fstrm s
  fstrm.open(s,mode)     can be a string or a pointer to a C-style
                         character string. The default file mode
                         depends on the type of fstream.
                         Returns void.
  fstrm.close()          closes the file to which fstrm is bound
                         retuns void
  fstrm.is_open()        returns a bool indicating whether the file
                         associated with fstrm was successfully opened
                         and has not been closed.

8.2.1. Using File Stream Objects

- Using an fstream in Place of an iostream&

    ```cpp
    ifstream input(argv[1]);            // open the file of sales transactions
    ofstream output(argv[2]);           // open the output file
    Sales_data total;                   // variable to hold the running sum

    if (read(input, total)) {           // read the first transaction
      Sales_data trans; // variable to hold data for the next transaction
      while(read(input, trans)) {       // read the remaining transactions
        if (total.isbn() == trans.isbn())   // check isbns
          total.combine(trans);         // update the running total
        else {
          print(output, total) << endl; // print the results
          total = trans;                // process the next book
        }
      }
      print(output, total) << endl;     // print the last transaction
    } else                              // there was no input
      cerr << "No data?!" << endl;
    ```
- The open and close Members

    ```cpp
    ifstream in(ifile); // construct an ifstreamand open the given file
    ofstream out; // output file stream that is not associated with any file
    out.open(ifile + ".copy"); // open the specified file
    ```
- Automatic Construction and Destruction

    ```cpp
    // for each file passed to the program
    for (auto p = argv + 1; p != argv + argc; ++p) {
      ifstream input(*p); // create input and open the file
      if (input) { // if the file is ok, ''process'' this file
        process(input);
      } else
        cerr << "couldn't open: " + string(*p);
    } // input goes out of scope and is destroyed on each iteration
    ```

8.2.2. File Modes

  in     open for input
  out    open for output
  app    seek to the end before every write
  ate    seek to the end immediately after the open
  trunc  truncate the file
  binary do IO operations in binary mode

- Opening a File in out Mode Discards Existing Data

    ```cpp
    // file1 is truncated in each of these cases
    ofstream out("file1"); // out and trunc are implicit
    ofstream out2("file1", ofstream::out); // trunc is implicit
    ofstream out3("file1", ofstream::out | ofstream::trunc);
    // to preserve the file's contents, we must explicitly specify app mode
    ofstream app("file2", ofstream::app); // out is implicit
    ofstream app2("file2", ofstream::out | ofstream::app);
    ```

- File Mode Is Determined Each Time open Is Called

    ```cpp
    ofstream out; // no file mode is set
    out.open("scratchpad"); // mode implicitly out and trunc
    out.close(); // close out so we can use it for a different file
    out.open("precious", ofstream::app); // mode is out and app
    out.close();
    ```

*/

/*
Section 8.3 string Streams
*/