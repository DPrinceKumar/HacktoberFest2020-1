// learn how to use the Browser fetch api in Javascript

async function fetchObjects() {
    let response = await fetch('https://objects.com');

    console.log(response.status); // 200
    console.log(response.statusText); // OK

    if (response.status === 200) {
        let data = await response.text();
        // handle data
    }
}

fetchObjects();