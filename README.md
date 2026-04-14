# 🧠 Math Quiz Game (C++)

An interactive **console-based Math Quiz Game** built with C++.
Test your math skills with different difficulty levels and operation types!

---

## 🎮 Features

* Multiple difficulty levels: Easy, Medium, Hard, Mixed
* Different operations: Addition, Subtraction, Multiplication, Division, Mixed
* Random question generation
* Tracks correct and wrong answers
* Final result (Pass / Fail)
* Replay option
* Color feedback (Green = correct, Red = wrong)

---

## 🛠️ How It Works

1. Choose number of questions
2. Select difficulty level
3. Select operation type
4. Solve the questions
5. View final result

---

## 🧩 Code Structure

* `enLevel` → Difficulty levels
* `enOpertionType` → Operation types
* `RandomNumber()` → Generate random numbers
* `Number()` → Get number based on level
* `SolveOpertion()` → Calculate result
* `CheckAnswer()` → Check answer
* `ResultBoard()` → Show results
* `Start()` → Game loop

---

## ▶️ Example

```
How Many Questions Do You Want To Answer? 5

Enter Question Level:
[1] Easy [2] Med [3] Hard [4] Mix

Enter Question Type:
[1] Add [2] Sub [3] Mul [4] Div [5] Mix

Question [1/5]
5
3  +
_________
8

Right Answer :-)
```

---

## 🚀 How to Run

Compile:

```
g++ main.cpp -o quiz
```

Run:

```
./quiz
```

---

## ⚠️ Notes

* Division by zero is handled
* Uses `rand()` for randomness
* Works best on Windows (uses `system("color")` and `system("cls")`)

---

## 📌 Future Improvements

* Add timer
* Add score percentage
* Save high scores
* Build GUI version

---

## 📜 License

Free to use and modify.

---
