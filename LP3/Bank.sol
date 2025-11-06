//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank {
    address public accHolder;
    uint balance = 0;

    constructor() {
        accHolder = msg.sender;
    }

    function deposit() public payable {
        require(msg.sender == accHolder, "You don't have access to this account!");
        require(msg.value > 0, "You Don't have enough ETH");
        balance += msg.value;
    }

    function withdraw(uint amount) public payable {
        require(msg.sender == accHolder, "You can not withdraw!");
        require(balance > 0, "You Don't have enough ETH");
        require(amount > 0, "Amount should be greater then 0");
        balance -= amount;
        payable(msg.sender).transfer(amount);
        
    }

    function showbalance() public view returns(uint){
        require(msg.sender == accHolder, "No access!");
        return balance;
    }
}