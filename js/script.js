document.getElementById('inputForm').addEventListener('submit', function(e) {
    e.preventDefault();
    
    const rows = parseInt(document.getElementById('rows').value);
    const slots = parseInt(document.getElementById('slots').value);
    const pools = parseInt(document.getElementById('pools').value);
    const serversCount = parseInt(document.getElementById('servers').value);
    const unavailableSlotsInput = document.getElementById('unavailableSlots').value;
    const serverDataInput = document.getElementById('serverData').value;

    const unavailableSlots = unavailableSlotsInput.split(';').map(pair => {
        const [r, s] = pair.split(',').map(Number);
        return { row: r, slot: s };
    });

    const servers = serverDataInput.split('\n').map(line => {
        const [size, capacity] = line.split(',').map(Number);
        return { size, capacity, allocated: false };
    });

    let pool = 0;
    const allocation = [];

    for (let i = 0; i < serversCount; i++) {
        let placed = false;
        for (let r = 0; r < rows && !placed; r++) {
            for (let s = 0; s <= slots - servers[i].size; s++) {
                if (canPlaceServer(r, s, servers[i].size, unavailableSlots, allocation, slots)) {
                    servers[i].allocated = true;
                    servers[i].row = r;
                    servers[i].slot = s;
                    servers[i].pool = pool;
                    allocation.push({ row: r, slot: s, size: servers[i].size });
                    pool = (pool + 1) % pools;
                    placed = true;
                    break;
                }
            }
        }
    }

    const results = servers.map(server => {
        return server.allocated ? `${server.row} ${server.slot} ${server.pool}` : 'x';
    }).join('\n');

    document.getElementById('results').textContent = results;
});

function canPlaceServer(row, slot, size, unavailableSlots, allocation, totalSlots) {
    for (let i = 0; i < size; i++) {
        if (slot + i >= totalSlots) return false;
        if (unavailableSlots.some(us => us.row === row && us.slot === slot + i)) return false;
        if (allocation.some(a => a.row === row && a.slot <= slot + i && slot + i < a.slot + a.size)) return false;
    }
    return true;
}
