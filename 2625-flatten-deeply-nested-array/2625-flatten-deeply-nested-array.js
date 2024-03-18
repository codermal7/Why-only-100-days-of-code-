/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, depth) {
    var result = [];
    
    flatten(arr, depth, result);
    
    return result;
};

function flatten(arr, depth, result) {
    for (var i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i]) && depth > 0) {
            flatten(arr[i], depth - 1, result);
        } else {
            result.push(arr[i]);
        }
    }
}