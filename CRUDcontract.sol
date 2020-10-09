// SPDX-License-Identifier: Undefined

pragma solidity ^0.7.0;

contract crud {

    struct User {
        uint id;
        string name;
    }

    User[] public users;
    uint public nextId;

    function create(string memory name) public {
        users.push(User(nextId, name));
        nextId++;
    }

    function read(uint id) public view returns(uint, string memory) {
        uint i = find(id);
        return (users[i].id, users[i].name);

    }

    function update(uint id, string memory name) public {
        uint i = find(id);
        users[i].name = name;
    }

    function del(uint id) public {
        uint i = find(id);
        delete users[i];
    }


    function find(uint id) view internal returns(uint){
        for (uint i; i < users.length; i++) {
            if (users[i].id == id) {
                return i;
            }
        }
        revert("Requested user does not exist");
    }
}