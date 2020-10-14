
// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.7.0;

contract SimpleStorage {
    string public data;

    function set(string memory _data) public{
        data = _data;
    }
}

