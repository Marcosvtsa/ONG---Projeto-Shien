const form = document.getElementById("paymentForm");

if (form) {

    form.addEventListener("submit", function(event) {

        const codigo = document.getElementById("codigo").value;
        const valor = document.getElementById("valor").value;

        const tipo = document.querySelector(
            'input[name="tipo"]:checked'
        );

        const message = document.getElementById("message");

        if (!/^\d{6}$/.test(codigo)) {

            event.preventDefault();

            message.textContent =
                "O código deve possuir exatamente 6 números.";

            return;
        }

        if (valor === "" || Number(valor) <= 0) {

            event.preventDefault();

            message.textContent =
                "Digite um valor válido.";

            return;
        }

        if (!tipo) {

            event.preventDefault();

            message.textContent =
                "Selecione o tipo de pagamento.";

            return;
        }

        console.log("Código:", codigo);
        console.log("Valor:", valor);
        console.log("Tipo:", tipo.value);

    });
}
