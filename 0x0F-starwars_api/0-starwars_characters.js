#!/usr/bin/node
const request = require('request');
const idFilm = process.argv[2];

let characters = [];
const names = [];

request(`https://swapi-api.hbtn.io/api/films/${idFilm}`, function (error, response, body) {
  if (error !== null) {
    console.error('error:', error);
  }
  const data = JSON.parse(body);
  characters = data.characters;
  characters.forEach((character, idx) => {
    request(`${character}`, function (error, response, body) {
      if (error !== null) {
        console.error('error:', error);
      }
      const data = JSON.parse(body);
      names[idx] = data.name;
      if (names.length === characters.length && !names.includes(undefined)) {
        names.forEach(name => {
          console.log(name);
        });
      }
    });
  });
});
