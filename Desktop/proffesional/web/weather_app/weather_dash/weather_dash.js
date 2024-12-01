const apiKey = 'Apikey'; // Replace  API key Here

function getWeather() {
  const city = document.getElementById('city').value;
  if (!city) {
    alert('Please enter a city name!');
    return;
  }

  fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`)
    .then(response => response.json())
    .then(data => {
      if (data.cod === 200) {
        displayWeather(data);
      } else {
        document.getElementById('weather-result').innerHTML = `<p>${data.message}</p>`;
      }
    })
    .catch(error => console.error('Error:', error));
}

function displayWeather(data) {
  const { name, main, weather, wind } = data;
  document.getElementById('weather-result').innerHTML = `
    <h2>Weather in ${name}</h2>
    <p>Temperature: ${main.temp}°C</p>
    <p>Weather: ${weather[0].description}</p>
    <p>Humidity: ${main.humidity}%</p>
    <p>Wind Speed: ${wind.speed} m/s</p>
  `;
}
