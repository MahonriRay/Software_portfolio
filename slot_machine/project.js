// 1 - User will deposit money
// 2 - Determine amount of lines user wants to play
// 3 - User will bet amount of money
// 4 - Spin the Slot Machine
// 5 - Determine if user won or lost
// 6 - If user won, calculate winnings, give no winnings if lost
// 7 - Play again

const prompt = require('prompt-sync')(); //Used to get user input

const rows = 3; //Rows of slot machine
const columns = 3; //Columns of slot machine
//How many symbols of each type
const symbolsCount = { 
    "A": 2,
    "B": 4,
    "C": 6,
    "D": 8,
};
// How much each symbol is worth
const symbolsValue = {
    "A": 5,
    "B": 4,
    "C": 3,
    "D": 2,
}



const depositMoney = () => {
    const depositAmt = prompt('How much money would you like to deposit?: '); //User input to determine amount of money to deposit
        const AmtNumber = parseFloat(depositAmt); //Converts user input to float
        if (isNaN(AmtNumber) || AmtNumber <= 0) { //Checks if user input is a number and is greater than 0
            console.log('Invalid Deposit Amount, please try again.');
            depositMoney();
        } else{
            return AmtNumber;
        }
}

const getLinesBet = () => {
    const lineNum = prompt('Enter the number of lines you would like to bet on (1-3): '); //User input to determine number of lines to bet on
    const lineNumInt = parseInt(lineNum); //Converts user input to integer
    if (isNaN(lineNumInt) || lineNumInt < 0 || lineNumInt > 3) { //Checks if user input is a number and is between 1 and 3
        console.log('Invalid number of lines, please try again.'); //If user input is not a number or is not between 1 and 3, prompts user to try again
        getLinesBet(); //Calls function again
    } else {
        return lineNumInt; //Returns user input if it is a number and is between 1 and 3
    }
}

const getBetAmt = (balanceAmt, linesBetOn) => {
    const betAmt = prompt('Enter the amount you would like to bet per line: '); //User input to determine amount to bet
    const betAmtFloat = parseFloat(betAmt); //Converts user input to float
    if (isNaN(betAmtFloat) || betAmtFloat <= 0 || betAmtFloat > (balanceAmt / linesBetOn)) { //Checks if user input is a number and is between 1 and 3
        console.log('Invalid bet amount, please try again.'); //If user input is not a number or is not between 1 and 3, prompts user to try again
        getBetAmt(); //Calls function again
    } else {
        return betAmtFloat; //Returns user input if it is a number and is between 1 and 3
    }
}

//Spins the slot machine
const spinSlot = () => {
    const symbols = [];
    //Creates an array of symbols based on the symbolsCount object
    for (const[symbol, count] of Object.entries(symbolsCount)) {
        for (let i = 0; i < count; i++) { //Loops through each symbol and adds it to the array according to the count
            symbols.push(symbol);
        }
    }
    const slotReels = [[],[],[]];
    for (let i = 0; i < columns; i++) {
        const reelSymbols = [...symbols] //Creates a copy of the symbols array so that it can be modified
        for (let j = 0; j < rows; j++){
            const selectedSymbol = reelSymbols[Math.floor(Math.random() * reelSymbols.length)]; //Selects a random symbol from the reelSymbols array
            slotReels[i].push(selectedSymbol);
            reelSymbols.splice(reelSymbols.indexOf(selectedSymbol), 1);
        }
    }
    return slotReels;
}

const displaySlot = (slotReels) => {
    const slotRows = [];

    //Creates an array of the rows of the slot machine
    for (let i = 0; i < rows; i++) {
        slotRows.push([]);
        for (let j = 0; j < columns; j++) {
            slotRows[i].push(slotReels[j][i]);
        }
    }
    return slotRows;
}

//Prints the rows of the slot machine
const printRows = (slotRows) => {
    for (const row of slotRows) {
        console.log(row.join(" | "));
    }
}

const getWinningLines = (rows, bet, lines) => {
    let winnings = 0; //Initializes winnings to 0
    for (let row = 0 ; row < lines; row++) { //Loops through each row
        const symbols = rows[row];
        let allSame = true;

        //Checks if all symbols in the row are the same
        for (const symbol of symbols) {
            if (symbol !== symbols[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) { //If all symbols are the same, winnings are calculated
            winnings += bet * symbolsValue[symbols[0]];
        }
    }
    return winnings;
}

//This is the main function that will run the game
const game = () => {
    let userMoney = depositMoney(); //let allows variable to be reassigned

    //Game loop, as long as user has money, or the desire to, they can play
    while(true){
        console.log(`\nBalance: $${userMoney}`);
        const linesBet = getLinesBet();
        const betAmount = getBetAmt(userMoney, linesBet);
        userMoney -= betAmount * linesBet; // Takes bet amount from user money per line
        const reels = spinSlot();
        const slots = displaySlot(reels);
        printRows(slots);
        const winnings = getWinningLines(slots, betAmount, linesBet);
        userMoney += winnings;
        console.log(`You won $${winnings}.\n`);

        if (userMoney <= 0) {
            console.log('You have no more money to bet with.');
            break;
        }

        const playAgain = prompt('Would you like to play again? (Y/N): ');
        if (playAgain != "y") {
            break;
        }
    }
}


let userMoney = depositMoney(); //let allows variable to be reassigned
console.log(`You have deposited $${userMoney}.`);
const linesBet = getLinesBet();
const betAmount = getBetAmt(userMoney, linesBet);
const reels = spinSlot();
const slots = displaySlot(reels);
printRows(slots);
const winnings = getWinningLines(slots, betAmount, linesBet);
console.log(`You won $${winnings}.\n`);

console.log(reels);
console.log(slots + "\n");

// game();