// Initialize the data for drawing on google map

// Initial center
var center = { lat: 23.78074, lng: 90.4076021 };

// global map objec. Constructed asynchronously
var map;
// initMap is calld by google map api and config goes in there
function initMap() {
    map = new google.maps.Map(document.getElementById('map'), {
        zoom: 18,
        center: center,
        mapTypeId: 'terrain'
    });
}


// take a map, center and color, then draw a circle on the map
function drawCircle(map, center, color) {
    var circle = new google.maps.Circle({
        strokeColor: color,
        strokeOpacity: 0.5,
        strokeWeight: 2,
        fillColor: color,
        fillOpacity: 0.35,
        map: map,
        //center must be lat(double) lng(double), so making sure
        center: { lat: parseFloat(center.lat), lng: parseFloat(center.lng) },
        radius: 25
    })
return circle;
}