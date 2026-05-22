# 🎮 ARCADE NUMBER GUESSER

> *A high-stakes, terminal-based number guessing game with dynamic difficulty levels and persistent stat tracking. Test your intuition, read the hints, and outsmart the system!*


[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Difficulty Levels: 3](https://img.shields.io/badge/Difficulty%20Levels-3-brightgreen.svg)](#-game-modes)
[![Status: Active](https://img.shields.io/badge/Status-Active-success.svg)](#)

---

## 🕹️ Quick Start

```bash
gcc -o number_guesser game.c
./number_guesser
```

Game loaded. Ready to play? `Choose your difficulty level...`

---

## ✨ Features

🎯 **Multiple Difficulty Modes**
- 🟢 **Easy** — Range: 1-50 | Lives: 10
- 🟡 **Medium** — Range: 1-100 | Lives: 7
- 🔴 **Hard** — Range: 1-200 | Lives: 5

📊 **Persistent Statistics Tracking**
- Total games played
- Win/loss ratio
- Personal best score (fewest attempts)
- Lifetime statistics dashboard

❤️ **Visual Life System**
- Real-time heart display: `<3 <3 <3` for remaining lives
- Intuitive visual feedback as lives deplete

🛡️ **Robust Input Validation**
- Bulletproof integer parsing
- Infinite loop protection
- Graceful handling of invalid input

💡 **Intelligent Hint System**
- Real-time directional guidance
- "Higher" or "Lower" feedback after each guess
- Strategic decision-making gameplay

---

## 🎮 How to Play

### The Objective
The computer picks a secret number. Your mission: **guess it before your lives run out.**

### Gameplay Loop
```
1. Choose your difficulty level (Easy/Medium/Hard)
2. Computer generates a random number in the selected range
3. Make your guess
4. Receive a hint (higher/lower)
5. Each wrong guess costs 1 life
6. Win by guessing correctly, lose by running out of lives
7. Track your performance across multiple rounds
```

### Example Session
```
==================================================
     WELCOME TO THE ARCADE NUMBER GUESSER!       
==================================================
-- Guess the number while balancing your finite lives.
-- Listen closely to the computer's hints to survive!

Choose your difficulty level:
1. Easy   (Range: 1-50,   10 Lives)
2. Medium (Range: 1-100,  7 Lives)
3. Hard   (Range: 1-200,  5 Lives)
Enter choice (1, 2, or 3): 2

[Medium Mode Enabled] Range 1-100. Stay focused.

Lives: [ <3 <3 <3 <3 <3 <3 <3 ]
Guess The Number: 50
Hint: Higher Number Please
----------------------------------------

Lives: [ <3 <3 <3 <3 <3 <3 X  ]
Guess The Number: 75
Hint: Lower Number Please
----------------------------------------

[... game continues ...]

🎉 CONGRATS! You beat the system!
The number was indeed 62.
You guessed it in 3 attempts.
🏆 NEW PERSONAL RECORD!
```

---

## 🔧 Technical Specifications

### Core Architecture

**Game Statistics Struct**
```c
typedef struct {    
    int total_games;      // Games initiated
    int games_won;        // Successful completions
    int best_score;       // Lowest attempts in a win
    int total_attempts;   // Cumulative guesses lifetime
} GameStats;
```

**Key Functions**
- `get_valid_int()` — Robust integer input with error recovery
- `print_lives()` — Visual ASCII heart display system
- `main()` — Game loop orchestration with statistics management

### Game Logic Flow
```
[Startup] 
    ↓
[Difficulty Selection] 
    ↓
[Random Number Generation] 
    ↓
[Guessing Loop: Validate → Compare → Provide Hint]
    ↓
[Win/Loss Determination] 
    ↓
[Update Statistics] 
    ↓
[Play Again?]
```

---

## 📋 System Requirements

| Requirement | Details |
|------------|---------|
| **Language** | C (C99 or later) |
| **Compiler** | GCC, Clang, or MSVC |
| **Memory** | < 1 MB |
| **CPU** | Any |
| **OS** | Linux, macOS, Windows (MinGW) |

---

## 🚀 Installation

### Option 1: Using GCC (Linux/macOS)
```bash
# Clone or download the repository
git clone https://github.com/yourusername/arcade-number-guesser.git
cd arcade-number-guesser

# Compile
gcc -o number_guesser game.c

# Run
./number_guesser
```

### Option 2: Using Clang
```bash
clang -o number_guesser game.c
./number_guesser
```

### Option 3: Windows (MinGW)
```bash
gcc -o number_guesser.exe game.c
number_guesser.exe
```

### Option 4: Online Compiler
- Use [repl.it](https://replit.com) or [OnlineGDB](https://www.onlinegdb.com)
- Paste the code and hit "Run"

---

## 🎯 Game Modes Breakdown

### 🟢 Easy Mode
**Perfect for:** Beginners, warm-up rounds
- **Range:** 1-50
- **Lives:** 10
- **Average Duration:** 2-3 minutes
- **Strategy:** Risk-taking, experimentation

### 🟡 Medium Mode (Default)
**Perfect for:** Regular players, balanced challenge
- **Range:** 1-100
- **Lives:** 7
- **Average Duration:** 3-5 minutes
- **Strategy:** Smart guessing with binary search principles

### 🔴 Hard Mode
**Perfect for:** Veterans, high-stakes gameplay
- **Range:** 1-200
- **Lives:** 5
- **Average Duration:** 5-8 minutes
- **Strategy:** Precision guessing, mathematical optimization

---

## 📊 Statistics Tracking

The game maintains a **Performance Dashboard** that displays:

```
==================================================
               YOUR CURRENT PERFORMANCE            
==================================================
 Total Games Handled : 15
 Games Successfully Won: 11
 Lifetime Guesses Fired: 87
 Best Winning Score    : 3 attempts
==================================================
```

**Use this to:**
- Track your improvement over time
- Identify your best difficulty level
- Challenge yourself to beat your personal record

---

## 💡 Pro Tips & Strategies

### Binary Search Strategy
The fastest way to find a number:
- Guess the **middle** of the range
- Adjust based on hint (higher/lower)
- Repeat with the narrowed range
- **Record:** Can solve even Hard mode in 7-8 guesses max!

### Life Management
- Play **Easy** to build confidence
- Use **Medium** to practice optimization
- Master **Hard** for the ultimate challenge

### Stat Optimization
- Track your win rate
- Aim to reduce attempts in each victory
- Challenge yourself to beat your best_score

---

## 🐛 Debugging & Troubleshooting

| Issue | Solution |
|-------|----------|
| **Compilation Error** | Ensure GCC/Clang is installed (`gcc --version`) |
| **Input Not Responding** | Press ENTER after typing your number |
| **Random Numbers Repeating** | This is normal — seed is set once per session |
| **Game Crashes on Text Input** | Input validation should handle this; report if it doesn't |

---

## 📝 Code Quality Features

✅ **Robust Input Handling**
- `get_valid_int()` prevents buffer overflow attacks
- Graceful recovery from non-integer input
- No infinite loops on bad input

✅ **Clean Architecture**
- Modular functions with single responsibility
- Clear variable naming conventions
- Well-commented code sections

✅ **Dynamic Game Parameters**
- Switch-based difficulty configuration
- Scalable statistics tracking
- Easy to extend with new features

---

## 🚀 Future Enhancements

- [ ] **Leaderboard System** — Save top scores to a file
- [ ] **Difficulty Presets** — Custom range/life combinations
- [ ] **Game History** — Log each round's details
- [ ] **Achievements** — Unlock badges for milestones
- [ ] **Multiplayer Mode** — Two-player guessing battles
- [ ] **Sound Effects** — Audio feedback for hints (if terminal supports)

---

## 🤝 Contributing

We welcome contributions! Here's how to help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Contribution Ideas
- Add new game modes
- Improve UI/visual elements
- Optimize the random number generation
- Add sound effects or color support
- Create language localization

---

## 📜 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

You are free to use, modify, and distribute this project, provided proper attribution is given.

---

## 👤 Author

**Your Name / Team**
- GitHub: [@yourusername](https://github.com/yourusername)
- Email: your.email@example.com
- Portfolio: [yourportfolio.com](https://yourportfolio.com)

---

## 🙏 Acknowledgments

- Inspired by classic arcade number guessing games
- Built with ❤️ in C
- Thanks to the open-source community for tools and inspiration

---

## 📞 Support & Feedback

Have questions or found a bug?

- 🐛 **Report Issues:** [GitHub Issues](https://github.com/yourusername/arcade-number-guesser/issues)
- 💬 **Discussions:** [GitHub Discussions](https://github.com/yourusername/arcade-number-guesser/discussions)
- 📧 **Email:** your.email@example.com

---

## 🎉 Did You Enjoy?

If you liked this game, please consider:
- ⭐ Starring the repository
- 🔗 Sharing with friends
- 🤝 Contributing improvements
- 💡 Suggesting new features

**Happy Guessing! 🎮**

---

<div align="center">

**Made with 💻 and ☕ by [Your Name]**

*Last Updated: 2024*

</div>
