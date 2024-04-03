/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
  try {
    const results = await Promise.all(functions.map(fn => fn()));
    return results;
  } catch (error) {
    throw error;
  }  
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */