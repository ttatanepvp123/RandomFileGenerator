mkdir tmp/
g++ *.cpp -o tmp/Linux32 -DLAST_COMMIT_ID=\"`git log --format="%H" -n 1`\" --static # For Linux 32bits
i686-w64-mingw32-g++ *.cpp -o tmp/Win32 -DLAST_COMMIT_ID=\"`git log --format="%H" -n 1`\" --static # For Windows 32bits
x86_64-w64-mingw32-g++ *.cpp -o tmp/Win64 -DLAST_COMMIT_ID=\"`git log --format="%H" -n 1`\" --static # For Windows 64bits