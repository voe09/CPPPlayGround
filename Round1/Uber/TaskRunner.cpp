Implement Task Runner.

TaskRunner takes concurrency as it's input. 'concurrency' is the number of the tasks that the TaskRunner can simultaneously execute. Keep pushing the tasks until the concurrency is reached. Once the limit is reached, wait for one of the tasks to be completed and then, execute other tasks.

function TaskRunner(concurrency) {
}

TaskRunner.prototype.push = function push(task) {
}

Example:

function exampleTask(done) {
/*calls done() at some point */
}

function exampleSimpleTask(done) {
setTimeout(done, Math.random() * 1000);
}

function exampleXhrTask(done) {
makeARequestSomehow('http://website.api/foo', function (err, res) {
doSomethingWithRes(res);
done();
});
}

var r = new TaskRunner(3);
// use the exampleSimpleTask from above;

r.push(exampleSimpleTask); // executes immediately
r.push(exampleSimpleTask); // executes immediately
r.push(exampleSimpleTask); // executes immediately
r.push(exampleSimpleTask); // should wait until one of the running tasks completes
r.push(exampleSimpleTask); // should wait until one of the running tasks completes
