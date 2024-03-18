class EventEmitter {
    constructor() {
        this.events = new Map();
    }
    
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
	subscribe(eventName, callback) {
        if(!this.events.has(eventName)) {
            this.events.set(eventName, [])
        }
        const listeners = this.events.get(eventName);
        listeners.push(callback);

		return {
            unsubscribe: () => {
                const index = listeners.indexOf(callback);
                if(index !== -1) {
                    listeners.splice(index, 1)
                }
			}
		};
	}
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
	emit(eventName, args = []) {
        if(!this.events.has(eventName)) {
            return []
        }
        
        const listeners = this.events.get(eventName);

        const results = []

        for (const listener of listeners) {
            results.push(listener(...args))
        }
		return results;
	}
}