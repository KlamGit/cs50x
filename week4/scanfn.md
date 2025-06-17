'''
scanf("%i\n", &n);

'''

The \n in scanf does not mean “skip any whitespace” — instead, it tells scanf:

“Wait until the user presses Enter and at least one non-whitespace character comes in after that.”

So, after typing 6 and pressing Enter, scanf is waiting for another character (because of \n). If you type another number like 3, it stores only 6 in n, and the 3 is left in the input buffer for the next input — or just ignored if there is no next scanf.

This is why you seem to have to enter two values, but only the first one is printed.

✅ The Correct Way
Just remove the \n from the format string:

c
Copy
Edit
scanf("%i", &n);
Then the program will:

Prompt with n:

Read one integer

Print it correctly

📌 Summary
You wrote	What it does
scanf("%i\n", &n);	Waits for a number, then also waits for another non-whitespace char after newline, causing confusing behavior
✅ scanf("%i", &n);	Correctly reads one integer, then continues