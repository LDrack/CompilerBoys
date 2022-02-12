.\MIECCompiler.exe -in ..\testfiles\ok\fibonacci.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\if.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\simple.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\arithmetic_operations\arit.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\arithmetic_operations\ArithLong.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\arithmetic_operations\DuplicateConst.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\arithmetic_operations\Multiplication.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\ok\arithmetic_operations\TestDivide.miec -out test.iex

.\MIECCompiler.exe -in ..\testfiles\failed\xfail_empty.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\failed\xfail_progWrong.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\failed\xfail_TestDivByZero.miec -out test.iex
.\MIECCompiler.exe -in ..\testfiles\failed\double_declaration\xfail_miecTestDoubleDecare.miec -out test.iex